#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
vector< int > primes;

const int N = int(1e4) + 10;
const int M = int(1e7) + 10;
bool is_composite[2 * M];
ll is_square[2 * M];
ll cdiv[2 * M];

void sieve(){
    for(int i = 2 ; i < 2 * M ; i++){
        if(!is_composite[i]){
            cdiv[i] = 2LL;
            for(int j = i + i ; j < 2 * M ; j += i){
                is_composite[j] = true;
                if(cdiv[j] == 0){
                    cdiv[j] = 1LL;
                }
                cdiv[j] <<= 1LL;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

int calc(int i){
    if(cdiv[i]){
        return cdiv[i];
    }

    int tmpi = i;
    cdiv[i] = 1;
    for(auto u: primes){
        if(u * u > tmpi){
            break;
        }

        if(tmpi % u == 0){
            cdiv[i] <<= 1LL;
        }
        while(tmpi % u == 0){
            tmpi /= u;
        }
    }

    if(tmpi != 1){
        cdiv[i] <<= 1LL;
    }

    // printf("r: %lld\n", cdiv[i]);
    return cdiv[i];
}

ll solve(ll i, ll c, ll d, ll x){
    ll o = x + d * i;
    // printf("o: %lld\n", o);
    if(o % (c * i) == 0){
        return calc(o / (c * i));
    }else{
        return 0LL;
    }
}

int main(){
    for(ll i = 1LL ; i * i < 2 * M ; i++){
        is_square[i * i] = 1LL; 
    }
    sieve();

    int t;

    scanf("%d", &t);
    
    while(t--){
        ll c, d, x;

        scanf("%lld %lld %lld", &c, &d, &x);

        ll ans = 0LL;

        for(ll i = 1LL ; i * i <= x ; i++){
            if(x % i == 0LL){
                ans += solve(i, c, d, x);

                if(x / i != i){
                    ans += solve(x / i, c, d, x);
                }
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}