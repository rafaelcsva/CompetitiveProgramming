//01, 04, 2019, 17:55:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(10);
vector< ll > primes;
bool is_composite[N];

ll fast_pow(ll number, int x, ll mod){
    ll r = 1LL;
    ll base = number;

    while(x){
        if(x & 1){
            r = (r * base) % mod;
        }

        base = (base * base) % mod;
        x >>= 1;
    }

    return r;
}

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;

    // printf("%lu\n", primes.size());
    scanf("%d", &t);
    
    while(t--){
        ll n, m;

        scanf("%lld %lld", &n, &m);

        ll g = 1LL;

        for(int i = 0 ; i < primes.size() ; i++){
            ll cur = primes[i];

            while((fast_pow(5LL, n, cur) + fast_pow(7LL, n, cur)) % cur == 0LL && 
                (fast_pow(5LL, m, cur) + fast_pow(7LL, m, cur)) % cur == 0LL){
                    cur = (primes[i] * cur);
                }

            cur /= primes[i];

            g = (g * cur);
        }

        cout << g << endl;
    }
    
    return 0;
}