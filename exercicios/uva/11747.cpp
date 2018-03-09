#include <bits/stdc++.h>

using namespace std;

typedef long double	ld;
typedef pair<int, int> pii;
typedef long long int	lli;
typedef pair<lli , pii> pipii;

const int N = 200100;
vector<pipii>edges;
vector<lli>ciclesEdges;
pii city[N];
int n, cost, tot, m;
int f[N];

int find(int x){
	if(f[x] == x){
		return x;
	}
	
	return f[x] = find(f[x]);
}

void join(int u, int v, lli dis){
	int x = find(u), y = find(v);
	
	if(x != y){
		//cout << "join " << u << ' ' << v << " with cost  " << dis << '\n';
		if(x > y){
			f[x] = y;
		}else{
			f[y] = x;
		}
	}else{
		ciclesEdges.push_back(dis);
	}
}

int main (){
	int t;
	int test = 0;	
	
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
		
		cost = 0, tot = 0;
		
		for(int i = 0 ; i < n ; i++){
			f[i] = i;
		}
		
		for(int i = 0 ; i < m ; i++){
			int k, j;
			lli w;
			
			scanf("%d%d%lld", &k, &j, &w);
			edges.push_back(make_pair(w, make_pair(k, j)));
			tot += w;
		}
		
		sort(edges.begin(), edges.end());
		
		for(int i = 0 ; i < edges.size() ; i++){
			pii ii = edges[i].second;
			lli w = edges[i].first;
			
			join(ii.first, ii.second, w);
		}
		
		sort(ciclesEdges.begin(), ciclesEdges.end());
		
		for(int i = 0 ; i < ciclesEdges.size() ; i++){
			char c = i == ciclesEdges.size() - 1 ? '\n' : ' ';
			
			printf("%lld%c", ciclesEdges[i], c);
		}
		
		if(ciclesEdges.size() == 0){
			printf("forest\n");
		}
		
		edges.clear();
		ciclesEdges.clear();
	}

	return 0;
}
