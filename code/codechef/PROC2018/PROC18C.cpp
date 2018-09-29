//16, 08, 2018, 12:49:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int D = 20, S = 9 * 18 + 4;
int d_upper[D], d_lower[D];
ll dp[S][2][2][D];
int used[S][2][2][D];
int test = 1;
const ll mod = (1e9 + 7);
const ll inverse = 500000004LL;

ll solve(int sum, bool flag1, bool flag2, int digt){
    if(sum < 0){
        return 0LL;
    }
    if(digt == 0){
        return sum == 0;
    }

    ll &ans = dp[sum][flag1][flag2][digt];
    int &us = used[sum][flag1][flag2][digt];

    if(us == test){
        return ans;
    }
    
    ans = 0LL;
    us = test;

    // if(is_first && d_lower[digt] == 0 && d_upper[digt] == 0){
    //     printf("pulei %d\n", digt);
    //     ans = solve(sum, flag1, flag2, digt - 1, is_first);
    // }else{
        // printf("%d\n", digt);
    if(!flag1 && !flag2){
        for(int i = d_lower[digt] ; i <= d_upper[digt] ; i++){
            // if(is_first && i == 0)
            //     continue;
                
            ans += solve(sum - i, i != d_upper[digt], i != d_lower[digt], digt - 1);
            ans %= mod;
        }
    }else if(!flag1){
        // printf("entrei aqui -- * no digito %d\n", digt);
        for(int i = 0 ; i <= d_upper[digt] ; i++){
                
            ans += solve(sum - i, i != d_upper[digt], flag2, digt - 1);
            ans %= mod;
        }
    }else if(!flag2){
        for(int i = d_lower[digt] ; i <= 9 ; i++){
                
            ans += solve(sum - i, flag1, i != d_lower[digt], digt - 1);
            ans %= mod;
        }
    }else{
        for(int i = 0 ; i <= 9 ; i++){
            ans += solve(sum - i, flag1, flag2, digt - 1);
            ans %= mod;
        }
    } 
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        memset(d_upper, 0, sizeof d_upper);
        memset(d_lower, 0, sizeof d_lower);

        ll l, r;

        scanf("%lld %lld", &l, &r);

        ll cnt = 0LL;
        
        int d = 1;

        while(l){
            d_lower[d++] = l % 10LL;
            l /= 10LL;
        }

        d = 1;

        while(r){
            d_upper[d++] = r % 10LL;
            r /= 10LL;
        }
        // printf("entrei\n");
        // solve(165, false, false, D - 1);
        // printf("o valor encontrado eh: %lld\n", dp[165][false][false][D - 1]);
        for(int k = 1 ; k < S ; k++){
            // printf("calculando para %d\n", k);
            solve(k, false, false, D - 1);
            // printf("o valor encontrado eh: %lld p k = %d\n", dp[k][false][false][D - 1], k);
        }
        // printf("sai\n");

        cnt = (((dp[1][false][false][D - 1] * (dp[1][false][false][D - 1] - 1LL)) % mod) * inverse);
        cnt %= mod;
        
        for(int i = 1 ; i < S ; i++){
            for(int j = i + 1 ; j < S ; j++){
                int g = __gcd(i, j);

                if(g == 1){
                    // printf("para %d e %d temos %lld x %lld\n", i, j, dp[i][false][false][D - 1], dp[j][false][false][D - 1]);
                    cnt += dp[i][false][false][D - 1] * dp[j][false][false][D - 1];
                    
                    cnt %= mod;
                }
            }
        }

        printf("%lld\n", cnt);
        test++;
    }

    return 0;
}