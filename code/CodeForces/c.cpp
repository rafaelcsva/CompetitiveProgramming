#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e6 + 10);
ll a[N];
int in[N];
int b[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);
	}

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &b[i]);
			
		if(b[i] != -1){
			b[i]--;
			in[b[i]]++;
		}
	}

	queue< int > q;

	for(int i = 0 ; i < n ; i++){
		if(in[i] == 0){
			q.push(i);
		}
	}

	ll ans = 0LL;

	vector< int > op;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		op.push_back(u);

		ans += a[u];

		if(b[u] != -1){
			a[b[u]] += a[u];
			in[b[u]]--;

			if(in[b[u]] == 0){
				q.push(b[u]);
			}
		}
	}

	printf("%lld\n", ans);

	for(int u: op){
		printf("%d ", u + 1);
	}

	printf("\n");

	return 0;
}