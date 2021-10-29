#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;
const int K = 18;
const int MAXN = 150010;
int LOG[MAXN+1];
ll st[4][MAXN][K + 1];
ll dp[4][MAXN];
ll a[4][MAXN];
vector< int > forb[4][MAXN];
const ll inf = ll(1e10);

void build(int p){
    for(int i = 0 ; i < MAXN ; i++){
        st[p][i][0] = dp[p][i];
    }
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= MAXN; i++)
            st[p][i][j] = min(st[p][i][j-1], st[p][i + (1 << (j - 1))][j - 1]);
}

ll query(int p, int L, int R){
    if(L > R){
        return inf;
    }

    int j = LOG[R - L + 1];
    ll minimum = min(st[p][L][j], st[p][R - (1 << j) + 1][j]);

    return minimum;
}

int main(){
    LOG[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        LOG[i] = LOG[i/2] + 1;
    
    int n[5];

    for(int i = 0 ; i < 4 ; i++){
        scanf("%d", &n[i]);
    }

    for(int p = 0 ; p < 4 ; p++){
        for(int i = 1 ; i <= n[p] ; i++){
            if(p != 3){
                forb[p][i].push_back(0);
                forb[p][i].push_back(n[p + 1] + 1);
            }

            scanf("%lld", &a[p][i]);
        }
    }

    for(int p = 0 ; p < 3 ; p++){
        int mi;

        scanf("%d", &mi);

        for(int i = 0 ; i < mi ; i++){
            int a, b;

            scanf("%d %d", &a, &b);

            forb[p][a].push_back(b);
        }
    }

    for(int p = 0 ; p < 4 ; p++){
        for(int i = 1 ; i <= n[p] ; i++){
            sort(forb[p][i].begin(), forb[p][i].end());
        }
    }

    for(int p = 3 ; p >= 0 ; p--){
        if(p == 3){
            for(int j = 1 ; j <= n[p] ; j++){
                dp[p][j] = a[p][j];
            }

            build(p);
        }else{
            for(int j = 1 ; j <= n[p] ; j++){    
                ll best = inf;

                for(int i = 0 ; i < forb[p][j].size() - 1 ; i++){
                    best = min(best, query(p + 1, forb[p][j][i] + 1, forb[p][j][i + 1] - 1));
                }
                // printf("best: %d\n", best + a[p][j]);
                dp[p][j] = a[p][j] + best;
            }

            build(p);
        }
    }

    ll ans = inf;

    for(int i = 1 ; i <= n[0] ; i++){
        ans = min(ans, dp[0][i]);
    }
    assert(ans >= 0);
    if(ans >= inf){
        printf("-1\n");
    }else{
        printf("%lld\n", ans);
    }

    return 0;
}
