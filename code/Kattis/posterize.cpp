#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< ll, ll >  pll;

const ll inf = ll(1e18);
const int N = 258;

ll cost[N][N];
ll dp[N][N];
ll r[N], p[N];

int main(){
    int d, k;

    scanf("%d %d", &d, &k);

    for(int i = 0 ; i < d ; i++){
        scanf("%lld %lld", &r[i], &p[i]);
    }

    for(int i = 0 ; i < d ; i++){
        ll sum1 = 0LL, sum2 = 0LL, sum3 = 0LL;

        for(int j = i ; j < d ; j++){
            sum1 += p[j] * r[j] * r[j];
            sum2 += p[j];
            sum3 += -2LL * r[j] * p[j];

            cost[i][j] = inf;

            for(int pixel = 0 ; pixel <= 255 ; pixel++){
                cost[i][j] = min(cost[i][j], sum1 + sum2 * pixel * pixel + sum3 * pixel);
            }
        }
    }

    for(int i = 0 ; i < d ; i++){
        dp[i][1] = cost[i][d - 1];
    }

    for(int j = 2 ; j <= k ; j++){
        for(int i = 0 ; i < d ; i++){
            dp[i][j] = inf;

            for(int e = i ; e < d ; e++){
                dp[i][j] = min(dp[i][j], cost[i][e] + dp[e + 1][j - 1]);    
            }
        }
    }

    printf("%lld\n", dp[0][k]);

    return 0;
}