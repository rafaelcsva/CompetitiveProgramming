#include <bits/stdc++.h>
 
using namespace std;
 
class Edge{
public:
	int a, b;
};
 
const int N = int(1e5 + 10);
typedef long long	ll;
 
vector< Edge > edges;
vector< vector< int > > adj;
vector< int > parent, depth, heavy, head, pos;
int cur_pos;
int n;
int carry[N];
int idx[N];
ll arr[N];
int bit[32][N];
int init_cor[N];

int LSOne(int x){
	return x & (-x);
}

int query(int x, int bit[]){
	int sum = 0;

	while(x > 0){
		sum += bit[x];
		x -= LSOne(x);
	}

	return sum;
}

void update(int x, int bit[]){
	while(x < N){
		bit[x] += 1;
		x += LSOne(x);
	}
}

int rsq(int l, int r, int bit[]){
	return query(r, bit) - query(l - 1, bit);
}

int dfs(int v){
	int size = 1;
	int max_c_size = 0;
 
	for(int c: adj[v]){
		if(c != parent[v]){
			parent[c] = v, depth[c] = depth[v] + 1;
			int c_size = dfs(c);
			size += c_size;
 
			if(c_size > max_c_size){
				max_c_size = c_size, heavy[v] = c;
			}
		}
	}
 
	return size;
}
 
void decompose(int v, int h){
	idx[cur_pos] = v;
	head[v] = h, pos[v] = cur_pos++;
 
	if(heavy[v] != -1){
		decompose(heavy[v], h);
	}
 
	for(int c: adj[v]){
		if(c != parent[v] && c != heavy[v]){
			decompose(c, c);
		}
	}
}
 
class Node{
public:
	int cor;
	bool ver = false;
};
 
const int inf = int(1e5);
ll lazzy[N << 2];
int lazzy1[N << 2];
Node segtree[N << 2];

void init(){
	int n = adj.size();
	parent = vector< int >(n);
	depth = vector< int >(n);
	heavy = vector< int >(n, -1);
	head = vector< int >(n);
	pos = vector< int >(n);
 
	cur_pos = 1;
 
	dfs(0);
 
	decompose(0, 0);
}
 
void query(int a, int b, int cor){
	bool ok = true;

	for(; head[a] != head[b] ; b = parent[head[b]]){
		if(depth[head[a]] > depth[head[b]]){
			swap(a, b);
		}
		
		int e = pos[b] - pos[head[b]] + 1;

		if(e != rsq(pos[head[b]], pos[b], bit[cor])){
			ok = false;
			break;
		}
	}
 
	if(pos[a] > pos[b]){
		swap(a, b);
	}
    
    int e = pos[b] - pos[a] + 1;

    if(e != rsq(pos[a], pos[b], bit[cor])){
    	ok = false;
    }
    
    if(!ok){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
}
 
void updatet(int a, int b){
	update(pos[a], bit[b]);
}
 
int main(){
	scanf("%d", &n);
 
	adj.resize(n);
 
	for(int i = 1 ; i < n ; i++){
		int ui, vi;
		scanf("%d %d", &ui, &vi);
 
		adj[ui].push_back(vi);
		adj[vi].push_back(ui);
	}
 
	int q;
 
	init();
 
	scanf("%d", &q);
 
	while(q--){
		int t;
 
		scanf("%d", &t);
 
		if(t == 2){
			int a, b;
 
			scanf("%d %d", &a, &b);
 			
 			if(init_cor[a] == 0){
				printf("NO\n");
			}else{
				query(a, b, init_cor[a]);
			}
		}else{
			int a, b;
			ll c;
 
			scanf("%d %d", &a, &b);
			init_cor[a] = b;
 
			updatet(a, b);
		}
	}
 
	return 0;
} 