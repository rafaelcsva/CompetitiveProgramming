#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(998244353LL);

const int N = int(2e6) + 10;
ll dp[N];
ll bag[N];

int main(){
    int st = 1LL;
    int d = 0;

    for(int i = 1 ; i < N ; i++){
        for(int j = i + i ; j < N ; j += i * 2){
            bag[j]++;
        }
    }

    // printf("end!\n");
    int n;
    
    scanf("%d", &n);

    ll sum = 0LL;
    ll add = 0LL;

    for(int i = 2 ; i <= 2 * n ; i += 2){
        dp[i] = sum + bag[i];

        if(dp[i] >= mod){
            dp[i] -= mod;
        }
        sum += dp[i];

        if(sum >= mod){
            sum -= mod;
        }
    }

    printf("%lld\n", dp[2 * n]);

    return 0;
}