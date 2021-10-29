#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int a[N];
int dp[N];
int cnt[N];
int used[N];
int test;
int val[N];
vector< int > ddiv[N];

int solve(int i){
    int &ans = dp[i];
    int &us = used[i];

    if(us == test){
        return ans;
    }

    us = test;

    ans = cnt[a[i]];
    for(auto u: ddiv[a[i]]){
        // printf("%d-> %d (%d)\n", a[i], a[u], u);
        ans = max(ans, solve(u) + cnt[a[i]]);
    }
    // printf("%d %d\n", i, ans);
    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }

        sort(a, a + n);

        for(int i = 0 ; i < n ; i++){
            val[a[i]] = i;
            dp[i] = 0;
            for(int j = 1 ; j * j <= a[i] ; j++){
                int o = a[i] / j;
                if((cnt[j] || cnt[o]) && a[i] % j == 0){
                    if(o != a[i] && cnt[o]){
                        // printf("%d->%d\n", o, i);
                        ddiv[i].push_back(o);
                    }
                    if(j != a[i] && cnt[j]){
                        ddiv[i].push_back(j);
                    }
                    // printf("%d->%d\n", j, i);
                }
            }
        }
        int ans = int(1e9) + 10;
        for(int i = n - 1 ; i >= 0 ; i--){
            dp[i] += cnt[a[i]];
            for(auto u: ddiv[i]){
                dp[val[u]] = max(dp[val[u]], dp[i]);
            }
            ans = min(ans, n - dp[i]);
        }

        printf("%d\n", ans);

        for(int i = 0 ; i < n ; i++){
            ddiv[i].clear();
            cnt[a[i]] = 0;
        }
    }

    return 0;
}
