#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int inf = int(1e9);

int dp[1 << N][N + 1];
bool used[1 << N][N + 1];
int adj[N];
int adj1[1 << N];
int n, m, k;

int solve(int mask, int r){
    bool &us = used[mask][r];
    int &ans = dp[mask][r];

    if(mask == 0){
        return ans = 1;        
    }

    if(us){
        return ans;
    }

    us = true;
    ans = inf;
    int best = inf;
    // if(mask == 8){
    //     printf("oitho!\n");
    // }
    best = 1 + solve(adj1[mask], k);

    if(r){
        for(int i = 0 ; i < n ; i++){
            int e = 1 << i;
            
            if((mask & e)){
                // if(mask == 10 && r == 1 && i == 1){
                //     printf("state = %d %d %d %d %d\n", best, mask ^ e, r - 1, solve(mask ^ e, r - 1), used[8][0]);
                // }
                best = min(best, solve(mask ^ e, r - 1));
            }
        }
    }

    // if(mask == 8 && r == 0){
    //     printf("m8,0 = %d\n", best);
    // }

    return ans = best;
}

vector< vector< char > > answers;

void get_ans(int mask, int r, vector< char > &tmp){
    if(mask == 0){
        answers.push_back(tmp);
        return;        
    }

    int &ans = dp[mask][r];

    if(ans == 1 + solve(adj1[mask], k)){
        answers.push_back(tmp);
        tmp.clear();
        // printf("--->%d, %d\n", mask, adj1[mask]);
        get_ans(adj1[mask], k, tmp);
        return;
    }

    if(r){
        for(int i = 0 ; i < n ; i++){
            int e = 1 << i;

            if((mask & e)){
                // if(answers.size() == 2 && i <= 1){
                //     printf("r = %d %d %d %d\n", solve(mask ^ e, r - 1), mask ^ e, i, r);
                // }
                if(ans == solve(mask ^ e, r - 1)){
                    tmp.push_back(char('a' + i));
                    get_ans(mask ^ e, r - 1, tmp);
                    break;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0 ; i < m ; i++){
        int ui, vi;

        scanf("%d %d", &ui, &vi);

        ui--, vi--;
        adj[ui] |= (1 << vi);
        adj[vi] |= (1 << ui);
    }

    for(int mask = 0 ; mask < (1 << n) ; mask++){
        for(int d = 0 ; d < n ; d++){
            int e = 1 << d;

            if(mask & e){
                adj1[mask] |= adj[d];
            }
        }
    }

    int d = solve((1 << n) - 1, k);
    if(d > 100){
        printf("-1\n");
        return 0;
    }

    vector< char > tmp;
    get_ans((1 << n) - 1, k, tmp);

    printf("%lu\n", answers.size());
    for(auto v: answers){
        for(auto u: v){
            printf("%c", u);
        }
        printf("\n");
    }

    return 0;
}
