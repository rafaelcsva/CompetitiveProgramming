//21, 09, 2018, 12:22:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef pair< pii, pii > pipii;

const int N = int(1e3);
bool mark[N][N];
map< pipii, bool > mp;
int n, m;

int solve(){
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            for(int k = 0 ; k < n ; k++){
                for(int t = 0 ; t < m ; t++){
                    int x = abs(i - k) + abs(j - t);

                    if(x == 3 && !mark[i][j] && !mark[k][t] && !mp[{{i, j}, {k, t}}]){
                        // printf("aqui!\n");
                        mark[i][j] = mark[k][t] = true;
                        mp[{{i, j}, {k, t}}] = true;
                        ans = max(ans, 2 + solve());
                        mark[i][j] = mark[k][t] = false;
                    }
                }
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &m);

    printf("%d\n", solve());

    return 0;
}