#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int n, m;
int v[N], p[N];
bitset<N>el(0);
bitset<N>resp;

int ans = 0;
vector<int>req[N];
int q;

void backtrack(int pos, int cat, int sum){
	if(pos == n){
		if(cat == m){
			//cout << el << '\n';
			//cout << sum << '\n';
			for(int i = 0 ; i < q ; i++){
				int cnt = 0;
			
				for(int j = 0 ; j < req[i].size() ; j++){
					if(el[req[i][j]] == 1){
						cnt++;
					}
				}
				
				if(cnt > 1)
					sum -= (cnt - 1) * p[i];
			//	cout << cnt << ' ' << p[i] << ' ' << sum << '\n';
			}
			//cout << sum << '\n';
			//cout << "\n**********\n";
			if(ans < sum){
				ans = sum;
				resp = el;
			}
		}
	}else{
		el[pos] = 1;
		
		backtrack(pos + 1, cat + 1, sum + v[pos]);
		
		el[pos] = 0;
		
		backtrack(pos + 1, cat, sum);
	}
}

int main (){
	int test = 1;
	bool ver = false;
	
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
		
		if(ver){
		//	printf("\n");
		}
		ver = true;
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}

		scanf("%d", &q);
		
		for(int i = 0 ; i < q ; i++){
			int t;
			
			scanf("%d", &t);
			
			for(int j = 0 ; j < t ; j++){
				int a;
				
				scanf("%d", &a);
				
				a--;
				
				req[i].push_back(a);
			}
			
			scanf("%d", &p[i]);
		}
		
		backtrack(0, 0, 0);
		
		printf("Case Number  %d\n", test++);
		printf("Number of Customers: %d\n", ans);
		printf("Locations recommended: ");
		int cat = 0;
		
		for(int i = 0 ; i < n ; i++){
			char c = cat == m - 1 ? '\n' : ' ';
			
			if(resp[i] == 1){
				printf("%d%c", i + 1, c);
				cat++;
			}
		}
		printf("\n");
		for(int i = 0 ; i < q ; i++){
			req[i].clear();
		}
		
		el.reset();
		ans = 0;
	}

	return 0;
}
