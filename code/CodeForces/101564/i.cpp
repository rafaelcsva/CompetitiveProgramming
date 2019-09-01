#include <bits/stdc++.h>

using namespace std;

const int N = int(2e3);
int key[N];

inline void writeChar(char c) {
    putchar(c);
}

template<typename T>
inline void write(T n){ 
    register int idx = 20; 
    if( n < 0 ) putchar('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar(out[idx++]); } while (out[idx] != ' '); 
} 

vector< int > st;
vector< int > path;
int con[N][N];
vector< int > adj[N];
int father[N];

bool dfs_key(int u, int ft, int target){
	if(key[u] == target){
		st.push_back(u);
		return true;
	}

	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];

		if(v == ft){
			continue;
		}

		if(dfs_key(v, u, target)){
			st.push_back(u);
			return true;
		}
	}

	return false;
}

void dfs(int u, int ft){
	father[u] = ft;

	for(int v: adj[u]){
		if(v == ft) continue;

		dfs(v, u);
	}
}

int solve(int x, int y){
	int ft = x;

	while(x != y){
		if(con[x][father[x]]){
			return con[x][father[x]];
		}

		x = father[x];
	}

	return -1;
}

int main(){
	int v, c, x, y;

	while(scanf("%d %d %d %d", &v, &c, &x, &y) != EOF){
		for(int k = 0 ; k < c ; k++){
			int xi;

			scanf("%d", &xi);

			key[xi] = k + 1;
		}

		for(int d = 0 ; d < v - 1 ; d++){
			int ui, vi, ky;

			scanf("%d %d %d", &ui, &vi, &ky);

			adj[ui].push_back(vi);
			adj[vi].push_back(ui);

			con[ui][vi] = con[vi][ui] = ky + 1;
		}

		dfs(y, y);

		bool ok = true;
		int r;

		while((r = solve(x, y)) != -1){
			dfs_key(x, x, r);

			if(st.size() == 0){
				ok = false;
				break;
			}

			for(int d = int(st.size()) - 1 ; d >= 0 ; d--){
				path.push_back(st[d]);
			}

			for(int k = 1 ; k < st.size() ; k++){
				path.push_back(st[k]);
			}

			int ft = x;

			while(ft != y){
				if(con[ft][father[ft]]){
					con[ft][father[ft]] = 0;
					break;
				}

				ft = father[ft];
			}

			st.clear();
		}

		int ft = x;

		if(path.size() == 0){
			path.push_back(x);
		}

		while(ft != y){
			path.push_back(father[ft]);
			ft = father[ft];
		}

		if(!ok){
			printf("Impossible\n");
		}else{
			assert(path.size() <= 4 * (c + 1) * v);

			printf("%d:", int(path.size()) - 1);

			for(auto u: path){
				printf(" %d", u);
			}

			printf("\n");
		}

		path.clear();

		for(int i = 0 ; i < v ; i++){
			adj[i].clear();
			father[i] = 0;

			for(int j = 0 ; j < v ; j++){
				con[i][j] = 0;
			}
		}

		for(int i = 0 ; i < c ; i++){
			key[i] = 0;
		}
	}

	return 0;
}