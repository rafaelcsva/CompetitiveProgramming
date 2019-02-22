//15, 11, 2018, 09:03:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int test;
const int N = 16;
ll dp[1 << N];
int used[1 << N];
int num[1 << N];
const int D = 8;
int vi[D] = {-1, -1, 0, 1, 1, 1, 0, -1};
int vj[D] = {0, 1, 1, 1, 0, -1, -1, -1};
int R, C;

bool ok(int l, int c){
    return 0 <= l && l < R && 0 <= c && c < C;
}

int LSOne(int x){
    return x & (-x);
}

ll solve(int mask){
    int t = __builtin_popcount(mask);

    if(t == 1){
        return 1LL;
    }

    ll &ans = dp[mask];

    if(used[mask] == test){
        return ans;
    }

    ans = 0LL;
    used[mask] = test;

    int tmask = mask;

    while(tmask){
        int cur = LSOne(tmask);
        tmask -= cur;

        int l = num[cur] / C;
        int c = num[cur] % C;
        int vmask = cur;

        // printf("%d, %d %d\n", l + 1, c + 1, cur);

        for(int i = 0 ; i < D ; i++){
            int xi = l + vi[i];
            int xj = c + vj[i];

            if(!ok(xi, xj)){
                continue;
            }

            int emask = 1 << (xi * C + xj);

            if(mask & emask){
                xi = l + 2 * vi[i];
                xj = c + 2 * vj[i];

                if(!ok(xi, xj)){
                    continue;
                }

                int dmask = 1 << (xi * C + xj);

                if(mask & dmask){
                    continue;
                }

                // printf("tirando %d %d indo para %d %d\n", l, c, xi, xj);

                ans += solve(((mask ^ emask) ^ vmask) | dmask);
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0 ; i < N ; i++){
        num[1 << i] = i;
    }    

    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        int n;

        scanf("%d %d %d", &R, &C, &n);

        int mask = 0;

        for(int i = 0 ; i < n ; i++){
            int x, y;

            scanf("%d %d", &x, &y);

            x--, y--;

            int emask = 1 << (x * C + y);
            // printf("\nmask = %d %d\n", emask, num[emask]);

            mask |= emask;
        }

        // cout <<"tenho bits = " << __builtin_popcount(mask) << endl;

        printf("Case %d: %lld\n", test, solve(mask));
    }

    return 0;
}