#include <bits/stdc++.h>

using namespace std;

const int N = 110;
char s[N][N];
vector< int > adj[N];
int match[N];
int vis[N];

int aug(int u){
	if(vis[u]){
		return 0;
	}

	vis[u] = 1;

	for(int v: adj[u]){
		if(match[v] == -1 || aug(match[v])){
			match[v] = u;
			return 1;
		}
	}

	return 0;
}

int main(){
	int t;
	int test = 1;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < n ; i++){
			scanf("\n%s", s[i]);

			for(int j = 0 ; j < m ; j++){
				if(s[i][j] == '1'){
					adj[i].push_back(j);
				}
			}
		}

		memset(match, -1, sizeof match);

		int bip = 0;

		for(int i = 0 ; i < n ; i++){
			if(aug(i)){
				bip++;
			}

			memset(vis, 0, sizeof vis);
		}

		printf("Case #%d: %d\n", test++, bip);

		for(int i = 0 ; i <= n ; i++) adj[i].clear();
	}

	return 0;
}