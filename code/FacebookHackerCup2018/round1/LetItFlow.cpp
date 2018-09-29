//21, 07, 2018, 14:04:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const ll mod = ll(1e9) + 7;
const int N = 1010;
const int L = 3;
int used[L][N][2];
ll dp[L][N][2];
int n;
char tab[L][N];
int test;

ll solve(int i, int j, int c){
    if(i == L - 1 && j == n){
        return 1LL;
    }
    
    if(i >= L || j >= n || j < 0 || i < 0 || tab[i][j] == '#'){
        return 0;
    }

    ll &ans = dp[i][j][c];

    if(used[i][j][c] == test){
        return ans;
    }

    used[i][j][c] = test;

    ans = 0LL;

    if(c == 0){
        ans = solve(i + 1, j, 1) + solve(i - 1, j, 1);
    }else{
        ans = solve(i, j + 1, 0);
    }

    return ans % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(test = 1 ; test <= t ; test++){

        cin >> n;
        
        for(int i = 0 ; i < L ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> tab[i][j];
            }
        }

        cout << "Case #" << test << ": " << solve(0, 0, 0) << endl;
    }

    return 0;
}