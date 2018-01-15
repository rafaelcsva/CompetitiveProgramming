#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int inf = (int) 1e9;
int resp[N];
vector<pair<int, pair<int, int> > > city;

void fill(int v[], int v1, int v2, int v3, int v4, int v5){
	v[0] = v1;
	v[1] = v2;
	v[2] = v3;
	v[3] = v4;
	v[4] = v5;
}

int test(int v1, int v2, int v3, int v4, int v5){
	int tmp = 0;

	for(int i = 0 ; i < city.size() ; i++){
		int tmp_ = inf;
		int x = city[i].second.first;
		int y = city[i].second.second;
		int d = city[i].first;
		
		tmp_ = min(tmp_, (abs((v1 / 5) - x) + abs((v1 % 5) - y)) * d);
		tmp_ = min(tmp_, (abs((v2 / 5) - x) + abs((v2 % 5) - y)) * d);
		tmp_ = min(tmp_, (abs((v3 / 5) - x) + abs((v3 % 5) - y)) * d);
		tmp_ = min(tmp_, (abs((v4 / 5) - x) + abs((v4 % 5) - y)) * d);
		tmp_ = min(tmp_, (abs((v5 / 5) - x) + abs((v5 % 5) - y)) * d);
		
		tmp += tmp_;
	}
	
	return tmp;
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		int n;
		
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			int x, y, d;
			
			scanf("%d%d%d", &x, &y, &d);
			
			city.push_back(make_pair(d, make_pair(x, y)));
		}
		
		int mn = inf;
		
		for(int of1 = 0 ; of1 < 25 ; of1++){
			for(int of2 = of1 + 1 ; of2 < 25 ; of2++){
				for(int of3 = of2 + 1 ; of3 < 25 ; of3++){
					for(int of4 = of3 + 1 ; of4 < 25 ; of4++){
						for(int of5 = of4 + 1 ; of5 < 25 ; of5++){
							int tmp = test(of1, of2, of3, of4, of5);
							
							if(tmp < mn){
								fill(resp, of1, of2, of3, of4, of5);
								
								mn = tmp;
							}
							

						}
					}
				}
			}
		}
		
		for(int i = 0 ; i < 5 ; i++){
			char c = i == 4 ? '\n' : ' ';
			
			printf("%d%c", resp[i], c);
		}
		
		city.clear();
	}

	return 0;
}
