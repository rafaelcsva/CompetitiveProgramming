#include <bits/stdc++.h>

using namespace std;

typedef long double	ld;
typedef pair<int, int> pii;
typedef pair<ld, pii > pipii;

const int N = 1010;
vector<pipii>edges;
pii city[N];
int n, r, nRail;
ld costRail, costRoad;
int f[N];
const ld EPS = 0.000000000000001L;

int find(int x){
	if(f[x] == x){
		return x;
	}
	
	return f[x] = find(f[x]);
}

void join(int u, int v, ld dis){
	int x = find(u), y = find(v);
	
	if(x != y){
		if(dis - r > EPS){
			nRail++;
			
			costRail += dis;
		}else{
			costRoad += dis;
		}
		
		if(x > y){
			f[x] = y;
		}else{
			f[y] = x;
		}
	}
}

int main (){
	int t;
	int test = 0;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &r);
		
		costRail = 0.0000000000000000L, costRoad = 0.00000000000000000L, nRail = 0;
		
		for(int i = 0 ; i < n ; i++){
			f[i] = i;
		}
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d%d", &city[i].first, &city[i].second);	
		}
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(j == i){
					continue;
				}
				
				int dx = city[i].first - city[j].first, dy = city[i].second -  city[j].second;
				
				edges.push_back(make_pair(sqrt(dx * dx + dy * dy), make_pair(i, j)));
			}
		}
		
		sort(edges.begin(), edges.end());
		
		for(int i = 0 ; i < edges.size() ; i++){
			pii ii = edges[i].second;
			ld dis = edges[i].first;
			
			join(ii.first, ii.second, dis);
		}
		
		cout << "Case #" << ++test << ": " << nRail + 1 << ' ' << int(round(costRoad)) << ' ' << int(round(costRail)) << '\n';
		edges.clear();
	}

	return 0;
}
