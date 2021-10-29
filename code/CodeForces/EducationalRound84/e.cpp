#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll pref[N];
const ll mod = ll(998244353LL);

int main(){
    pref[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        pref[i] = (10LL * pref[i - 1]) % mod;
    }

    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        ll sum = 0LL;

        if(i == n){
            sum = 10;
        }else{
            sum = (((pref[n - 1 - i] * ll(n - i - 1LL)) % mod) * 9LL * 9LL) % mod;

            sum += ((2LL * pref[n - 1 - i]) * 10LL * 9LL);
            sum %= mod;
        }

        printf("%lld ", sum);
    }
    printf("\n");

    return 0;
}