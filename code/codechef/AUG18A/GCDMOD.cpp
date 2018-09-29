//03, 08, 2018, 10:44:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll MOD = 1e9 + 7;
vector< ll > divisors;

ll fast_pow(ll a, ll x, ll &mod){
    if(x == 0LL){
        return 1LL;
    }

    if(x == 1LL){
        return a;
    }

    ll lf = fast_pow(a, x / 2LL, mod);
    lf *= lf;

    lf %= mod;

    if(x & 1LL){
        lf *= a;
    }

    return lf % mod;
}

bool test(ll f, ll a, ll b, ll n){
    ll r1 = fast_pow(a, n, f);
    ll r2 = fast_pow(b, n, f);

    return ((r1 + r2) % f) == 0LL;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        ll a, b, n;

        scanf("%lld %lld %lld", &a, &b, &n);

        ll d = abs(a - b);

        if(d == 0LL){
            printf("%lld\n", (fast_pow(a, n, MOD) + fast_pow(a, n, MOD)) % MOD);
        }else{
            for(ll f = 1LL ; f * f <= d ; f++){
                if(d % f == 0LL){
                    divisors.push_back(f);

                    divisors.push_back(d / f);
                
                }
            }

            ll best = 1;

            for(ll f: divisors){
                if(test(f, a, b, n)){
                    best = max(best, f);  
                }
            }

            printf("%lld\n", best % MOD);
            
            divisors.clear();
        }
    }

    return 0;
}