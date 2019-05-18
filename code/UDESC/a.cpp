#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

typedef long double	ld;
typedef pair< ll, ll >	plll;
typedef pair< int, ll >	pll;

const int N = int(2e5 + 10);
int ffather[N];
vector< pll > adj[N];

class Edge{
	public:
	int u, v;
	ll w;

	Edge(int u, int v, ll w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

vector< Edge > edges, other;

bool comp(Edge &u, Edge &v){
	return u.w < v.w;
}

int find(int x){
	if(x == ffather[x]){
		return x;
	}

	return ffather[x] = find(ffather[x]);
}

bool join(int u, int v){
	int x = find(u);
	int y = find(v);

	if(x != y){
		if(x < y){
			ffather[y] = x;
		}else{
			ffather[x] = y;
		}

		return true;
	}

	return false;
}

const int LOGN = 20;
int L[2 * N], E[2 * N], H[N], idx;
int LCA[2 * N][LOGN];
int father[2 * N][LOGN];
ll best1[N][LOGN];
ll best2[N][LOGN];

void dfs(int cur, int depth){
   H[cur] = idx;
   E[idx] = cur;
   L[idx++] = depth;

   for(int i = 0 ; i < adj[cur].size() ; i++){
       int v = adj[cur][i].first;
       ll w = adj[cur][i].second;

       if(H[v] == -1){
           father[v][0] = cur;
           best1[v][0] = w;

           dfs(v, depth + 1);
           E[idx] = cur;
           L[idx++] = depth;
       }
   }
}

void buildRMQ(int n){
   idx = 0;
   memset(H, -1, sizeof H);

   dfs(0, 0); 
	// printf("n: %d\n", n);
   n *= 2;

   for(int i = 0 ; i < n ; i++){
       LCA[i][0] = i;
   }

   for(int i = 1 ; (1 << i) <= n ; i++){
       for(int j = 0 ; j + (1 << i) - 1 < n ; j++){
           int sz = 1 << (i - 1);
          
           if(L[LCA[j][i - 1]] < L[LCA[j + sz][i - 1]]){
               LCA[j][i] = LCA[j][i - 1];
           }else{
               LCA[j][i] = LCA[j + sz][i - 1];
           }
       }
   }
}

void buildParent(int n){
   for(int k = 1 ; k < LOGN ; k++){
       for(int i = 0 ; i < n ; i++){
           father[i][k] = father[father[i][k - 1]][k - 1];

           best1[i][k] = best1[i][k - 1];
           best2[i][k] = best2[i][k - 1];

           ll other = best1[father[i][k - 1]][k - 1];

           if(best1[i][k] < other){
           		best2[i][k] = best1[i][k];
           		best1[i][k] = other;
           }

           other = best2[father[i][k - 1]][k - 1];
       	
			if(best1[i][k - 1] != other){
				best2[i][k] = max(best2[i][k], other);
			}
       }
   }
}

plll query_parent(int u, int k){ // retorna o k'esimo pai do nó u
   int cur = u;
   ll besta = 0LL, bestb = 0LL;

   for(int i = 0 ; i < LOGN ; i++){
		int e = 1 << i;

		if(k & e){
			if(best1[cur][i] > besta){
				bestb = besta;
				besta = best1[cur][i];
			}

			if(besta != best2[cur][i]){
				bestb = max(bestb, best2[cur][i]);
			}

			cur = father[cur][i];
		}
   }

   return {besta, bestb};
}

int query(int u, int v){// Retorna o LCA de u e v, O(1)
   int i = H[u], j = H[v];
  
   if(i > j){
       swap(i, j);
   }

   int sz = (int)floor(log(ld(j - i + 1)) / (log(2.0L)));

   if(L[LCA[i][sz]] < L[LCA[j - (1 << sz) + 1][sz]]){
       return E[LCA[i][sz]];
   }else{
       return E[LCA[j - (1 << sz) + 1][sz]];
   }
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0 ; i < n ; i++){
		ffather[i] = i;
	}

	for(int i = 0 ; i < m ; i++){
		int ui, vi;
		ll w;

		scanf("%d %d %lld", &ui, &vi, &w);
		ui--, vi--;

		edges.push_back(Edge(ui, vi, w));
	}

	sort(edges.begin(), edges.end(), comp);

	ll tot = 0LL;

	for(int i = 0 ; i < edges.size() ; i++){
		if(join(edges[i].u, edges[i].v)){
			// printf("%d, %d\n", edges[i].u, edges[i].v);
			tot += edges[i].w;

			adj[edges[i].u].push_back({edges[i].v, edges[i].w});
			adj[edges[i].v].push_back({edges[i].u, edges[i].w});
		}else{
			other.push_back(edges[i]);
		}
	}

	buildRMQ(n);
	buildParent(n);

	ll best = ll(1e18);
	// printf("TOT  = %lld\n", tot);
	// printf("lca = %d\n", query(2, 1));

	for(int i = 0 ; i < other.size() ; i++){
		Edge e = other[i];

		int lca = query(e.u, e.v);
		// printf("lca = %d u = %d v = %d lca\n", lca, e.u, e.v);

		int diff = abs(L[H[lca]] - L[H[e.u]]);
		int diff2 = abs(L[H[lca]] - L[H[e.v]]);
		
		plll d = query_parent(e.u, diff);
		plll g = query_parent(e.v, diff2);

		// printf("%lld %lld %lld %lld\n", d.first, d.second, g.first, g.second);
		if(d.first){
			if(e.w != d.first){
				best = min(best, tot - d.first + e.w);
			}
		}

		if(d.second){
			if(e.w != d.second){
				best = min(best, tot - d.second + e.w);
			}
		}

		if(g.first){
			if(e.w != g.first){
				best = min(best, tot - g.first + e.w);
			}
		}

		if(g.second){
			if(e.w != g.second){
				best = min(best, tot - g.second + e.w);
			}
		}
	}

	if(best != ll(1e18)){
		printf("%lld\n", best);
	}else{
		printf("-1\n");
	}

	return 0;
}