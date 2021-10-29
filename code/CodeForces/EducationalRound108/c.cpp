#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
vector< int > teams;
const int N = int(2e5) + 10;
bool mark[N];
int u[N];
ll s[N];
vector< ll > streng[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &u[i]);

            if(!mark[u[i]]){
                teams.push_back(u[i]);
                mark[u[i]] = true;
            }
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &s[i]);
            streng[u[i]].push_back(s[i]);
        }

        for(int u: teams){
            streng[u].push_back(0LL);
            sort(streng[u].begin(), streng[u].end());

            for(int i = 0 ; i < streng[u].size() ; i++){
                if(i){
                    streng[u][i] += streng[u][i - 1];
                }
            }
        }

        int r = 1;

        while(r <= n){
            ll ans = 0LL;
            vector< int > fteam;

            for(auto u: teams){
                int sz = int(streng[u].size());
                ll add = streng[u][sz - 1] - streng[u][(sz - 1) % r];

                if(add != 0){
                    fteam.push_back(u);
                }
                ans += add;
            }

            teams = fteam;

            printf("%lld ", ans);
            r++;
        }

        printf("\n");

        for(int i = 1 ; i <= n ; i++){
            mark[i] = false;
            streng[i].clear();
        }
        teams.clear();
    }

    return 0;
}