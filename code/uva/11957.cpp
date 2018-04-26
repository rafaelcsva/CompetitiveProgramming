#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
typedef pair<int, int>  pii;
const int N = 110;
char tab[N][N];
ll dp[N][N];
int n;
const ll mod = ll(1000007);

pii cord(int i, int j, int mod){
    if(i < 0 || j < 0 || i >= n || j >= n){
        return {-1, -1};
    }

    if(tab[i][j] == 'B'){
        if(mod == 2){
            return {-1, -1};
        }

        if(mod){
            return cord(i - 1, j + 1, 2);
        }else{
            return cord(i - 1, j - 1, 2);
        }
    }else{
        return {i, j};
    }
}

int main (){
    int t;
    int test = 1;

    ios::sync_with_stdio(false);

    cin >> t;

    while(t--){
        cin >> n;
        memset(dp, 0LL, sizeof dp);

        int lin, col;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> tab[i][j];

                if(tab[i][j] == 'W'){
                    lin = i, col = j;
                }
            }
        }

        dp[lin][col] = 1;

        for(int l = lin ; l >= 0 ; l--){
            for(int c = 0 ; c < n ; c++){
                pii ii = cord(l - 1, c + 1, 1);

                if(ii.first != -1){
                    dp[ii.first][ii.second] += dp[l][c];
                    dp[ii.first][ii.second] %= mod;
                }

                ii = cord(l - 1, c - 1, 0);

                if(ii.first != -1){
                    dp[ii.first][ii.second] += dp[l][c];
                    dp[ii.first][ii.second] %= mod;
                }
                
            }
        }

        ll r = 0LL;

        for(int c = 0 ; c < n ; c++){
            r += dp[0][c];
            r %= mod;
        }

        cout << "Case " << test++ << ": " << r << endl;
    }

    return 0;
}