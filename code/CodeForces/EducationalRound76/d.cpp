#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5 + 10), K = 20;
int idx[N];
int st1[N][K], st2[N][K];
int str[N];
int a[N];
int LOG[N];

void build1(int n){
	for (int i = 0; i < n; i++)
   		st1[i][0] = a[i];

	for (int j = 1; j < K; j++)
	    for (int i = 0; i + (1 << j) <= n; i++)
	        st1[i][j] = max(st1[i][j-1], st1[i + (1 << (j - 1))][j - 1]);
}

int query1(int L, int R){
	if(L > R){
		return N;
	}

	int j = LOG[R - L + 1];
	return max(st1[L][j], st1[R - (1 << j) + 1][j]);
}

void build2(int n){
	for (int i = 0; i < n; i++)
   		st2[i][0] = str[i];

	for (int j = 1; j < K; j++)
	    for (int i = 0; i + (1 << j) <= n; i++)
	        st2[i][j] = max(st2[i][j-1], st2[i + (1 << (j - 1))][j - 1]);
}

int query2(int L, int R){
	int j = LOG[R - L + 1];
	return max(st2[L][j], st2[R - (1 << j) + 1][j]);
}

vector< int > cl;

int main(){
	LOG[1] = 0;
	for (int i = 2; i < N ; i++)
	    LOG[i] = LOG[i / 2] + 1;

	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		int m;

		scanf("%d", &m);

		for(int i = 0 ; i < m ; i++){
			int pi, si;

			scanf("%d %d", &pi, &si);

			str[si] = max(str[si], pi);
			cl.push_back(si);
		}

		build1(n);
		build2(n + 1);

		int i = 0;

		int days = 0;

		while(i < n){
			int lo = i;
			int hi = n - 1;
			int r = -1;

			while(lo <= hi){
				int mid = (lo + hi) >> 1;
				int re = query1(i, mid);
				int len = mid - i + 1;
				int e = query2(len, n);
				// printf("(%d-%d) %d %d\n", i, mid, re, e);

				if(e >= re){
					lo = mid + 1;
					r = mid;
				}else{
					hi = mid - 1;
				}
			}

			if(r == -1){
				days = -1;
				break;
			}

			// printf("%d-%d\n", i, r);

			i = r + 1;
			days++;
		}

		printf("%d\n", days);

		for(int u: cl){
			str[u] = 0;
		}

		cl.clear();
	}

	return 0;
}