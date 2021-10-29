#include <bits/stdc++.h>

using namespace std;

const int N = 210;
int dp[N][N][5][5];
vector< pair< int, int > > ansres[N][N][5][5];
int mp[6] = {0, 25, 25, 25, 25, 15};

int solve(int a, int b, int ma, int mb){
    if(a < 0 || b < 0) return 0;

    int &ans = dp[a][b][ma][mb];
    
    // if(ma < 0 || mb < 0)
    // printf("%d, %d\n", ma, mb);
    if(ans != -1){
        // printf("ret on %d %d %d %d\n", a, b, ma, mb);
        return ans;
    }

    ans = 0;
    // printf("%d %d %d %d\n", )
    if((ma + mb) == 0){
        // printf("ret on %d %d %d %d\n", a, b, ma, mb);
        return ans = (a + b) == 0;
    }

    if(ma > mb){
        for(int i = 0 ; i <= min(mp[ma + mb] - 2, b) ; i++){
            ans |= solve(a - mp[ma + mb], b - i, ma - 1, mb);

            if(ans){
                auto &ansr = ansres[a][b][ma][mb];
                ansr = ansres[a - mp[ma + mb]][b - i][ma - 1][mb];
                ansr.push_back({mp[ma + mb], i});
                // printf("(%d, %d) %d %d\n", a - mp[ma + mb], b - i, mp[ma + mb], i);

                return ans;
            }
        }

        for(int i = mp[ma + mb] + 1 ; i <= a; i++){
            ans |= solve(a - i, b - (i - 2), ma - 1, mb);

            if(ans){
                auto &ansr = ansres[a][b][ma][mb];
                ansr = ansres[a - i][b - (i - 2)][ma - 1][mb];
                // printf("gives %d %d %d\n", a - i, b - (i - 2), solve(a - i, b - (i - 2), ma - 1, mb));
                ansr.push_back({i, i - 2});
                // printf("%d-%d %d-%d %d %d\n", i, i - 2, a, b, ma, mb);

                return ans;
            }
        }
    }else{
        for(int i = 0 ; i <= min(mp[ma + mb] - 2, a) ; i++){
            ans |= solve(a - i, b - mp[ma + mb], ma, mb - 1);

            if(ans){
                auto &ansr = ansres[a][b][ma][mb];
                ansr = ansres[a - i][b - mp[ma + mb]][ma][mb - 1];
                ansr.push_back({i, mp[ma + mb]});
                // printf("%d %d\n", i, mp[ma + mb]);

                return ans;
            }
        }

        for(int i = mp[ma + mb] + 1 ; i <= b; i++){
            ans |= solve(a - (i - 2), b - i, ma, mb - 1);

            if(ans){
                auto &ansr = ansres[a][b][ma][mb];
                ansr = ansres[a - (i - 2)][b - i][ma][mb - 1];
                // printf("%d %d\n", i - 2, i);
                ansr.push_back({i - 2, i});

                return ans;
            }
        }
    }

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    int t;

    scanf("%d", &t);

    while(t--){
        int a, b;

        scanf("%d %d", &a, &b);

        bool ver = false;
    
        for(int i = 0 ; i <= 2 ; i++){
            if(solve(a, b, 3, i)){
                printf("%d:%d\n", 3, i);
                for(auto u: ansres[a][b][3][i]){
                    printf("%d:%d ", u.first, u.second);
                }
                printf("\n");
                ver = true;
                break;
            }
        }

        if(!ver){
            for(int i = 2 ; i >= 0 ; i--){
                if(solve(a, b, i, 3)){
                    printf("%d:%d\n", i, 3);
                    for(auto u: ansres[a][b][i][3]){
                        printf("%d:%d ", u.first, u.second);
                    }
                    printf("\n");
                    ver = true;
                    break;
                }
            }
        }

        if(!ver){
            printf("Impossible\n");
        }
        // printf("deu!?");
    }

    return 0;
}