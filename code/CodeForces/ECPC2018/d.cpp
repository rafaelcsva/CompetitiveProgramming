#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = int(1e5 + 10);
ll a[N + 10];
int arr[N + 10];
ll sum[N + 10];
vector< int > diiv[N + 10];
int cur_test = 1;
bool is_composite[N + 10];
ll ret[N + 10];
int mark[N + 10];
const ll mod = ll(1e9 + 7);

void sieve(){
	for(int i = 2 ; i * i < N ; i++){
		if(!is_composite[i]){
			arr[i] = i;

			for(int j = i + i ; j < N ; j += i){
				if(arr[j] == 0){
					arr[j] = i;
				}

				is_composite[j] = true;
			}
		}
	}
}

int main(){
	freopen("lcm.in", "r", stdin);
	
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j * j <= i ; j++){
			if(i % j == 0){
				diiv[i].push_back(j);

				if(j * j != i){
					diiv[i].push_back(i / j);
				}
			}
		}

		sort(diiv[i].begin(), diiv[i].end(), greater< int >());
	}

	sieve();

	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++) scanf("%lld", &a[i]);

		for(int i = 0 ; i < n ; i++){
			for(int d: diiv[a[i]]){
				sum[d] += a[i];
			}
		}

		ll ans = 0LL;

		for(int i = 0 ; i < n ; i++){
			ll tmp = 0LL;

			for(int d: diiv[a[i]]){
				tmp += ((sum[d] - ret[d]) * a[i]) / d;
				// printf("+%lld (%lld, %lld, %lld, %lld)\n", ((sum[d] - ret[d]) * a[i]) / d, d, sum[d] - ret[d], sum[d], ret[d]);
				ans += ((sum[d] - ret[d]) * a[i]) / d;
				ans %= mod;

				for(int e: diiv[d]){
					if(e == d) continue;

					ret[e] += (sum[d] - ret[d]);
					// printf("e: %lld + %lld %lld\n", e, sum[d] - ret[d], d);
				}
			}
			// printf("=%lld\n", tmp);

			for(int d: diiv[a[i]]){
				ret[d] = 0LL;
			}
		}

		printf("%lld\n", ans);
		memset(sum, 0LL, sizeof sum);
	}

	return 0;
}