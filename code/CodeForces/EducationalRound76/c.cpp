#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5 + 10), K = 20;
int idx[N];
int st[N][K];
int a[N];
int LOG[N];

void build(int n){
	for (int i = 0; i < n; i++)
   		st[i][0] = a[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= n; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R){
	if(L > R){
		return N;
	}

	int j = LOG[R - L + 1];
	return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main(){
	memset(idx, -1, sizeof idx);

	LOG[1] = 0;
	for (int i = 2; i < N ; i++)
	    LOG[i] = LOG[i / 2] + 1;

	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			int ai;

			scanf("%d", &ai);

			a[i] = n + 1;

			if(idx[ai] != -1){
				a[idx[ai]] = i;
			}

			idx[ai] = i;
		}

		build(n);

		int best = N;

		for(int i = 0 ; i < n ; i++){
			if(a[i] != n + 1){
				if(query(i + 1, a[i] - 1) > a[i]){
					best = min(best, a[i] - i + 1);
				}
			}
		}

		if(best == N){
			printf("-1\n");
		}else{
			printf("%d\n", best);
		}

		for(int i = 0 ; i < n ; i++){
			idx[i + 1] = a[i] = -1;
		}
	}

	return 0;
}