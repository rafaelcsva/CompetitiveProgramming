#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair< int, int >    pii;

const int N = 510;
ll dp[N][N];
const ll mod = ll(998244353);
ll num[N];
char op[N];
int se;
int n;

int is_lesser(int i, int j){
    pii a = make_pair(num[i], i);
    pii b = make_pair(num[j], j);

    return a < b;
}

ll solve(int i, int l){
    if(l < 0){
        return 0LL;
    }

    if(i > se && l == 0){
        return 0LL;
    }

    // printf("%d, %d\n", i, l);

    if(i == n){
        return 1LL;
    }

    ll &ans = dp[i][l];

    if(ans != -1LL){
        return ans;
    }

    ans = 0LL;

    if(i == se){
        ans = solve(i + 1, l + 1);
    }else{
        ans = solve(i + 1, l);
        
        if(op[i] == '+'){
            ans += solve(i + 1, l + is_lesser(i, se));

            if(ans >= mod){
                ans -= mod;
            }
        }else{
            ll q = solve(i + 1, max(l - 1, 0));
            // printf("aqui em %d, %d add %lld on %lld\n", i, l, q, ans);
            ans += q;

            if(ans >= mod){
                ans -= mod;
            }
        }
    }

    // printf("%d, %d = %lld\n", i, l, ans);

    return ans;
}

ll cnt[N];

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("\n%c", &op[i]);

        if(op[i] == '+'){
            scanf("%lld", &num[i]);
        }
    }

    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        if(op[i] == '+'){
            memset(dp, -1, sizeof dp);
            se = i;
            ll add = solve(0, 0);
            // printf("%lld shows %lld and adds %lld | i counted %lld mr Wayne\n", num[i], add, (add * num[i]) % mod, cnt[i]);

            ans = ((add * num[i]) % mod + ans) % mod;
            // tot += num[i] * cnt[i];
        }
    }

    printf("%lld\n", ans);

    return 0;
}