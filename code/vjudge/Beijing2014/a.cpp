#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 10010;
pair< ll, ll > p[N];

int main(){
	int t;

	scanf("%d", &t);
	int test = 1;

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%lld %lld", &p[i].first, &p[i].second);
		}

		sort(p, p + n);

		ll d = 1, num = 0;

		for(int i = 0 ; i < n - 1 ; i++){
			ll num1 = abs(p[i].second - p[i + 1].second);
			ll d1 = p[i + 1].first - p[i].first;

			if(num * d1 < num1 * d){
				num = num1;
				d = d1;
			}
		}

		printf("Case #%d: %.2lf\n", test++, double(num) / double(d));
	}

	return 0;
}