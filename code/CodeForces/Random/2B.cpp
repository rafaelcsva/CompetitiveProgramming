//02, 12, 2018, 17:23:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1000;
ll t[N][N];
int dp[N][N][100];
int n;

int get(ll &mod, int i, int j){
    int num = 0;
    mod *= t[i][j];

    if(mod == 0){
        return 0;
    }

    while(mod % 10LL == 0){
        num++;
        mod /= 10LL;
    }

    mod %= 100LL;
    return num;
}

int solve(int i, int j, ll mod){
    int &ans = dp[i][j][mod];
    
    if(ans != -1){
        return ans;
    }   

    if(i == n - 1 && j == n - 1){
        return ans = 0LL;
    }

    if(i >= n || j >= n){
        return ans = 1e9;
    }

    ll mod1 = mod;

    int val = get(mod1, i + 1, j);

    ans = solve(i + 1, j, mod1) + val;

    mod1 = mod;
    val = get(mod1, i, j + 1);
    ans = min(solve(i, j + 1, mod1) + val, ans);

    return ans;
}

void print_path(int i, int j, ll mod){
    // cout << i << " " << j << endl;
    if(i == n - 1 && j == n - 1){
        return;
    }

    int ans = dp[i][j][mod];

    ll mod1 = mod;

    int val = get(mod1, i + 1, j);

    if(ans == dp[i + 1][j][mod1] + val){
        cout << "D";
        print_path(i + 1, j, mod1);
    }else{
        mod1 = mod;
        val = get(mod1, i, j + 1);

        cout << "R";
        print_path(i, j + 1, mod1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);
    
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> t[i][j];
        }
    }

    ll mod = 1LL;
    int val = get(mod, 0, 0);

    cout << solve(0, 0, mod) + val << endl;
    print_path(0, 0, mod);
    cout << endl;

    return 0;
}