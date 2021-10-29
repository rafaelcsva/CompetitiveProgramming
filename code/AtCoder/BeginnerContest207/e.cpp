#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 3010;
int sz[N];
pair< int, int > prec[N][N];
ll pref[N];
const ll mod = ll(1e9) + 7LL;
ll dp[N][N];
int n;

ll solve(int i, int k){
    if(i == n + 1){
        return 1LL;
    }
    if(i > n){
        return 0LL;
    }

    ll &ans = dp[i][k];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    ll pmod = pref[i - 1] % k;

    auto bg = *lower_bound(prec[k], prec[k] + sz[k], make_pair((int)pmod, i));

    if(bg.first == pmod){
        ans = solve(bg.second + 1, k + 1);
        if(bg.second < n){
            ans += solve(bg.second + 1, k);
        
            if(ans >= mod){
                ans -= mod;
            }
        }
    }

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);

    ll sum = 0;

    for(int i = 1 ; i <= n ; i++){
        ll ai;

        scanf("%lld", &ai);

        sum += ai;
        pref[i] = sum;
    
        for(ll d = 1LL ; d <= n ; d++){
            prec[d][sz[d]++] = make_pair(sum % d, i);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        prec[i][sz[i]++] = make_pair(i + 1, n + 1);
        sort(prec[i], prec[i] + sz[i]);
    }

    printf("%lld\n", solve(1, 1));

    return 0;
}