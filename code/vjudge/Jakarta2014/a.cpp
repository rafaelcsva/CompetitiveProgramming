#include <bits/stdc++.h>

using namespace std;

const int N = int(110);
int a[N];
int test = 1;
int mark[N];
int n, k;

int dfs(int u){
	mark[u] = test;

	for(int i = u + 1 ; i < n ; i++){
		if(a[i] - a[u] > k){
			break;
		}

		if(mark[i] == test) continue;

		dfs(i);
	}
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &k);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		sort(a, a + n);

		int cnt = 0;

		for(int i = 0 ; i < n ; i++){
			if(mark[i] != test){
				dfs(i);
				cnt++;
			}
		}

		printf("Case #%d: %d\n", test, cnt);

		test++;
	}

	return 0;
}