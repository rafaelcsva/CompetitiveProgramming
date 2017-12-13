#include <bits/stdc++.h>

using namespace std;

const int N = 300100, mod = (int) 1e9 + 7;
long long int nodes[N], fib[N];
vector<long long int> graph[N];
int cor[N], current;
long long int m = 0;

void build(){
	fib[1] = 1;
	
	for(int i = 2 ; i < N ; i++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
		m = max(m, fib[i]);
	}
}

void dfs(int v, int k, long long int a, long long int b, int d){
	if(k < 0){
		return;
	}

	long long int sum = 0;

	if(d == 2){
		sum = (a + b) % mod;
	}else if(d == 1){
		sum = b % mod;
	}else if(d == 0){
		sum = a % mod;
	}else{
		sum = ((fib[d] * b) % mod + (fib[d - 1] * a) % mod) % mod;
	}

	nodes[v] = (sum + nodes[v]) % mod;
	cor[v] = current;
	
	for(int i = 0 ; i < graph[v].size() ; i++){
		if(cor[graph[v][i]] != current){
			dfs(graph[v][i], k - 1, a, b, d + 1);	
		}
	}

}

void test(long long int a,long long int b){
	long long int x0 = a + b;
	long long int x1 = a % mod + (2 * b) % mod;

	for(int i = 3; i < N ; i++){
		long long int tmp = x1;
		x1 = (x0 + x1) % mod;
		x0 = tmp % mod;
	
		if(x0 != ((fib[i] * b) % mod + (fib[i - 1] * a) % mod) % mod){
			printf("%d %lld %lld\n", i, ((fib[i] * b) % mod + (fib[i - 1] * a) % mod) % mod, x0);
		}
	}
	printf("END\n");
}

int main (){
	int t;
	
	scanf("%d", &t);

	build();
	//test(0, 897987897);
	//printf("MAX: %lld %lld\n", m * 1000000000, m);
	while(t--){
		int n, q;

		scanf("%d %d", &n, &q);
		
		for(int i = 0 ; i < n - 1 ; i++){
			int x, y;

			scanf("%d %d", &x, &y);
			
			x--;
			y--;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for(int i = 1 ; i <= q ; i++){
			int op, v, k;
			long long int a, b;

			current = i;

			scanf("%d", &op);

			if(op == 1){
				scanf("%d %d %lld %lld", &v, &k, &a, &b);
				v--;

				dfs(v, k, a, b, 0);
			}else{
				scanf("%d", &v);
				v--;
			
				printf("%lld\n", nodes[v]);
			}
		}

		for(int i = 0 ; i < n ; i++){
			cor[i] = 0;
			nodes[i] = 0;
			graph[i].clear();
		}
	}
	
	return 0;
}
