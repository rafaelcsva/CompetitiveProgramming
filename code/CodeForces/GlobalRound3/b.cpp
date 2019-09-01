#include <bits/stdc++.h>

using namespace std;

typedef long long 	ll;

const int N = int(1e6);
ll a[N], b[N];

int main(){
	int n, m, k;
	ll ta, tb;

	scanf("%d %d %lld %lld %d", &n, &m, &ta, &tb, &k);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);
	}

	for(int i = 0 ; i < m ; i++){
		scanf("%lld", &b[i]);
	}

	if(k >= n || k >= m){
		printf("-1\n");
	}else{
		int i = 0;
		int j = k;
		int pt = j;
		ll mx = 0LL;

		while(i <= k){
			int idx = lower_bound(b, b + m, a[i] + ta) - b;

			if(idx + (k - i) >= m){
				printf("-1\n");
				return 0;
			}

			mx = max(mx, b[idx + k - i] + tb);
			i++;
		}

		printf("%lld\n", mx);
	}

	return 0;
}