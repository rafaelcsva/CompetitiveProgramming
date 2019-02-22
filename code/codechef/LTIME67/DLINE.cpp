//29, 12, 2018, 13:43:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll, ll> pii;
typedef pair< ll, pii > pipii;

const int N = 2030;
vector< pii > lines[N];
ll dp[N][N];
const ll inf = 2e15;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    //cout << int(2e9 + 2000) << endl;

    cin >> t;

    while(t--){
        int n;
        ll p;

        cin >> n >> p;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                dp[i][j] = inf;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            int y, s, e;

            cin >> y >> s >> e;

            lines[y].push_back({s, e});
        }

        int last = 0;

        for(int i = 0 ; i < N ; i++){
            if(lines[i].size() == 0){
                continue;
            }

            sort(lines[i].begin(), lines[i].end());
        }

        int tmp = 0;
        int best = 0;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j <= lines[i].size() ; j++){
                ll cur_cost = i;
                ll add;

                if(j){
                    add = lines[i][j - 1].second;
                    cur_cost += add;
                } 

                for(int d = 0 ; d + j < N ; d++){
                    if(i == 0){
                        dp[i][d + j] = cur_cost + add + dp[i - 1][d + j];
                    }else{
                        dp[i][d + j] = min(dp[i][d + j], cur_cost + add + dp[i - 1][d + j]);
                    }

                    ll de;

                    if(i == 0){
                        if(d + j > lines[0].size()){
                            break;
                        }
                        
                        de = cur_cost;
                    }else{
                        de = cur_cost + dp[i - 1][d + j];
                    }

                    if(de <= p){
                        best = max(best, d + j);
                    }
                }
            }
        }

        printf("%d\n", best);

        // all_lines.clear();

        for(int i = 0 ; i < N ; i++){
            lines[i].clear();
        }
    }
    
    return 0;
}