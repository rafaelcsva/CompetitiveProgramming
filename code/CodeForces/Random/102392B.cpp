#include <bits/stdc++.h>
 
using namespace std;
 
const int N = int(1000 + 1);
const int K = 501;
typedef long long   ll;
ll dp[N][N][2];
const ll inf  = ll(1e18);
int x[N], y[N];
ll t[N], r[N];
 
ll mmin(ll a, ll b){
    if(a == -1){
        return b;
    }
 
    if(b == -1){
        return a;
    }
 
    return min(a, b);
}

int ind[N];

bool compar(int a, int b){
    return x[a] < x[b];
}

int main(){
    memset(dp, -1, sizeof dp);
 
    int n, s1, s2;
 
    scanf("%d %d %d", &n, &s1, &s2);
 
    for(int i = 1 ; i <= n ; i++){
        scanf("%d %lld %d %lld", &x[i], &t[i], &y[i], &r[i]);
        ind[i] = i;
    }
    
    sort(ind + 1, ind + 1 + n, compar);

    dp[0][0][0] = 0;
 
    ll ans = inf;
 
    for(int k = 1 ; k <= n ; k++){
        dp[0][0][k & 1] = 0;
 
        for(int i = 0 ; i <= s1 ; i++){
            for(int j = 0 ; j <= s2 ; j++){
                ll mn = inf;
 
                if(dp[i][j][k & 1] == -1){
                    continue;
                }
 
                dp[i][j][(k + 1) & 1] = mmin(dp[i][j][(k + 1) & 1], 
                    dp[i][j][k & 1]);
 
                int a1 = min(i + x[ind[k]], s1);
                int a2 = j;
 
                if(i + x[ind[k]] > s1 && i != s1){
                    a2 += i + x[ind[k]] - s1;
                }
 
                int bb = min(j + y[ind[k]], s2);
                
                dp[a1][a2][(k + 1) & 1] = mmin(
                    dp[a1][a2][(k + 1) & 1],
                    dp[i][j][k & 1] + t[ind[k]]
                );           
 
                dp[i][bb][(k + 1) & 1] = mmin(
                    dp[i][bb][(k + 1) & 1],
                    dp[i][j][k & 1] + r[ind[k]]
                );
 
                if(i >= s1 && j >= s2){
                    ans = min(ans, dp[i][j][(k + 1) & 1]);
                }
 
                if(a1 >= s1 && a2 >= s2){
                    ans = min(ans, dp[a1][a2][(k + 1) & 1]);
                }
 
                if(i >= s1 && j + y[ind[k]] >= s2){
                    ans = min(ans, dp[i][bb][(k + 1) & 1]);
                }
            }
        }
    }
 
    printf("%lld\n", ans == inf ? -1 : ans);
 
    return 0;
}