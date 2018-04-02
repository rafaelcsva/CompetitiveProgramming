#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
typedef long double	ld;
const int N = 1010;
ld cost = 0.00000L;
pii p[N];
int f[N];
vector<pair<ld, pii> > edges;
int comp;

int find(int x){
	if(f[x] == x){
		return x;
	}
	
	return f[x] = find(f[x]);
}

void join(int u, int v, ld dis){
	int x = find(u), y = find(v);
	
	if(x != y){
		cost = max( dis, cost);
		comp--;
		
		if(x > y){
			f[x] = y;
		}else{
			f[y] = x;
		}
	}
}

int main (){
	int n;
	
	scanf("%d", &n);
	
	while(n--){
		int s, t;
		
		cost = 0.000000L;
		
		scanf("%d%d", &s, &t);
		
		for(int i = 0 ; i < t ; i++){
			f[i] = i;
		}
		
		for(int i = 0 ; i < t ; i++){
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		
		comp = t;
		
		for(int i = 0 ; i < t ; i++){
			for(int j = 0 ; j < t ; j++){
				if(i == j)
					continue;
					
				int dx = p[i].first - p[j].first, dy = p[i].second - p[j].second;
				
				edges.push_back(make_pair(sqrt(dx * dx + dy * dy), make_pair(i, j)));
			}
		}	
		
		sort(edges.begin(), edges.end());
		
		for(int i = 0 ; i < edges.size() && comp != s ; i++){
			pii ii = edges[i].second;
			
			join(ii.first, ii.second, edges[i].first);
		}
		
		cout << setprecision(2) << fixed << cost << '\n';
		edges.clear();
	}

	return 0;
}
