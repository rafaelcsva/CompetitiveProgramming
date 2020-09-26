#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e6 + 10);
ll a[N];
int in[N];
int b[N];
ll dp[N];
ll aa[N];
vector< int > fadj[N], adj[N], top;
bool vis[N];

void dfs(int u){
	vis[u] = true;

	for(int v: adj[u]){
		if(vis[v]) continue;

		dfs(v);
	}

	top.push_back(u);
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);
		aa[i] = a[i];
	}

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &b[i]);
			
		if(b[i] != -1){
			b[i]--;
			in[b[i]]++;
			fadj[b[i]].push_back(i);
		}
	}

	queue< int > q;

	for(int i = 0 ; i < n ; i++){
		if(in[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();

		if(b[u] != -1){
			a[b[u]] += max(a[u], 0LL);
			in[b[u]]--;

			if(in[b[u]] == 0){
				q.push(b[u]);
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int u: fadj[i]){
			if(a[u] > 0){
				adj[i].push_back(u);
				in[u]++;
			}else{
				adj[u].push_back(i);
				in[i]++;
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(!vis[i] && in[i] == 0){
			dfs(i);
		}
	}

	ll ans = 0LL;

	for(int u: top){
		ans += aa[u];

		if(b[u] != -1){
			aa[b[u]] += aa[u];
		}
	}

	printf("%lld\n", ans);

	for(int u: top){
		printf("%d ", u + 1);
	}

	printf("\n");

	return 0;
}