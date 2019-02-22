//15, 11, 2018, 12:20:59 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 200;
string numbers[N];
int test = 1;
const int sz = 1 << 12;
int dp[sz][sz];
int used[sz][sz];
int cnt[sz][sz];
int m, n;
const int inf = 1e9;

int solve(int choose, int resp){
    if(cnt[choose][resp] <= 1){
        return 0;
    }

    int &ans = dp[choose][resp];

    if(used[choose][resp] == test){
        return ans;
    }
    
    used[choose][resp] = test;
    ans = 1e9;

    for(int i = 0 ; i < m ; i++){
        int e = 1 << i;

        if((choose & e) == 0){
            ans = min(ans, 
                1 + max(solve(choose | e, resp | e),
                    solve(choose | e, resp)
                )
            );
        }
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> m >> n;

        if(m == 0 && n == 0){
            break;
        }

        for(int i = 0 ; i < n ; i++){
            cin >> numbers[i];
        }

        for(int i = 0 ; i < (1 << m) ; i++){
            // cout << "***************" << endl;
            // bitset< 8 > bst(i);
            // cout << bst << endl;

            for(int t = 0 ; t < n ; t++){
                int tmp = 0;

                for(int j = 0 ; j < m ; j++){
                    int e = 1 << j;

                    if((i & e)){
                        if(numbers[t][j] == '1'){
                            tmp |= e;
                        }
                    }
                }
                // cout << tmp << endl;

                cnt[i][tmp]++;
            }

        }

        cout << solve(0, 0) << endl;
        test++;

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}