#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = 52;
int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll x[N];

ll calc(int msk){
    ll ans = 1LL;

    for(int j = 0 ; j < 15 ; j++){
        int e = 1 << j;

        if(msk & e){
            ans *= primes[j];
        }
    }

    return ans;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &x[i]);
    }

    ll ans = ll(1e18);

    for(int msk = 1 ; msk < (1 << 15) ; msk++){
        bool ok = true;

        for(int i = 0 ; i < n ; i++){
            bool tmp = false;
            for(int j = 0 ; j < 15 ; j++){
                int e = 1 << j;
                if(msk & e){
                    if(x[i] % primes[j] == 0){
                        tmp = true;
                        break;
                    }
                }
            }

            if(!tmp){
                ok = false;
                break;
            }
        }

        if(ok){
            ans = min(ans, calc(msk));
        }
    }

    printf("%lld\n", ans);

    return 0;
}