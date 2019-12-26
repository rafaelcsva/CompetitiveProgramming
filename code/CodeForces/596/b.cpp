#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
map< string, ll > cnt;
vector< ll > primes;
const int N = int(1e5 + 10);
bool is_composite[N];

void sieve(){
	for(int i = 2 ; i * i < N ; i++){
		if(!is_composite[i]){
			for(int j = i + i ; j < N ; j += i){
				is_composite[j] = true;
			}
		}
	}

	for(ll i = 2 ; i < N ; i++){
		if(!is_composite[i]){
			primes.push_back(i);
		}
	}
}

string tstr(ll a, ll b){
	string s = to_string(a);
	string t = to_string(b);

	return "(" + s + "|" + t + ")";
}

void add(string &a, string b){
	for(int i = 0 ; i < b.length() ; i++){
		a.push_back(b[i]);
	}
}

int main(){
	int n, k;

	scanf("%d %d", &n, &k);

	if(k >= 36){
		ll ones = 0LL;
		ll tot = 0LL;

		for(int i = 0 ; i < n ; i++){
			ll ai;

			scanf("%lld", &ai);

			if(ai == 1LL){
				tot += ones;
				ones++;
			}
		}

		printf("%lld\n", tot);
	}else{
		sieve();

		ll tot = 0LL;

		for(int i = 0 ; i < n ; i++){
			ll ai;

			scanf("%lld", &ai);

			string tmp = "-";
			string comp = tmp;

			for(ll u: primes){
				if(u * u > ai){
					break;
				}

				ll t = 0;

				while(ai % u == 0LL){
					ai /= u;
					t++;
				}

				t %= k;

				if(t){
					add(tmp, tstr(u, t));
					add(comp, tstr(u, (k - t) % k));
				}
			}

			if(ai != 1LL){
				ll t = 1LL;

				t %= k;

				if(t){
					add(tmp, tstr(ai, t));
					add(comp, tstr(ai, (k - t) % k));
				}
			}

			if(cnt.count(comp)){
				tot += cnt[comp];
			}

			cnt[tmp]++;
		}

		printf("%lld\n", tot);
	}

	return 0;
}