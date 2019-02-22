//03, 02, 2019, 15:25:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll inverso[N];
const ll mod = ll(1e9 + 7);

ll fast_pow(ll n, ll x){
    if(x == 0LL){
        return 1LL;
    }

    if(x == 1LL){
        return n;
    }

    ll l = fast_pow(n, x / 2LL);

    l *= l;
    l %= mod;

    if(x & 1LL){
        l *= n;
        l %= mod;
    }

    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    inverso[1] = 1LL;
	for(ll i = 2 ; i < N ; i++){
		inverso[i] = (mod - (mod / i) * inverso[mod % i] % mod) % mod;
	}

    int t;
    
    scanf("%d", &t);

    while(t--){
        int n, k, m;

        scanf("%d %d %d", &n, &k, &m);

        if(m & 1){
            ll p = (n - 1LL) * inverso[n];
            p %= mod;
            
            ll sum = -1LL * (fast_pow(p, m / 2 + 1) - 1LL) * n;

            sum = ((sum % mod) + mod) % mod;

            printf("%lld\n", (((sum * inverso[n]) % mod) + mod) % mod);
        }else{
            ll p = (n - 1LL) * inverso[n];
            
            p %= mod;

            ll sum = -1LL * (fast_pow(p, m / 2) - 1LL) * n;

            sum = ((sum % mod) + mod) % mod;

            ll add = fast_pow(p, m / 2) * inverso[n + k];

            add %= mod;

            printf("%lld\n", ((((sum * inverso[n]) % mod + add) % mod) + mod) % mod);
        }   
    }

    return 0;
}