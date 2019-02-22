//17, 02, 2019, 18:56:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5000;
int dp[N][N];
int nxta[N][2];
int nxtb[N][2];
string a, b;

int solve(int i, int j){
    if(i == a.length() && j == b.length()){
        return 0;
    }

    int &ans = dp[i][j];

    if(ans != -1){
        return ans;
    }

    ans = min(
        solve(max(nxta[i][0], i), max(nxtb[j][0], j)),
        solve(max(nxta[i][1], i), max(nxtb[j][1], j))
    ) + 1;

    return ans;
}

void print_dp(int i, int j){
    if(i == a.length() && j == b.length()){
        return;
    }

    int ans = dp[i][j];

    if(ans == solve(max(nxta[i][0], i), max(nxtb[j][0], j)) + 1){
        cout << 0;
        print_dp(max(nxta[i][0], i), max(nxtb[j][0], j));
    }else{
        cout << 1;
        print_dp(max(nxta[i][1], i), max(nxtb[j][1], j));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> a >> b;

    int f0a = a.length(), f1a = a.length();
    int f0b = b.length(), f1b = b.length();

    for(int i = f0a - 1 ; i >= 0 ; i--){
        nxta[i][0] = f0a;   
        nxta[i][1] = f1a;

        if(a[i] == '0'){
            f0a = i;
        }else{
            f1a = i;
        }
    }

    for(int i = f0b - 1 ; i >= 0 ; i--){
        nxtb[i][0] = f0b;
        nxtb[i][1] = f1b;

        if(b[i] == '0'){
            f0b = i;
        }else{
            f1b = i;
        }
    }

    if(solve(f0a, f0b) <= solve(f1a, f1b)){
        cout << '0';
        print_dp(f0a, f0b);
    }else{
        cout << '1';
        print_dp(f1a, f1b);
    }

    cout << endl;
    // cout << min(, ) + 1 << endl;
    
    return 0;
}