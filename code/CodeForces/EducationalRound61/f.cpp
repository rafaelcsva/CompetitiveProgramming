//05, 03, 2019, 13:05:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 510;
int match[N];
int carry[N];
int dp[N][N][2];
int n;
const int inf = 1e9;

int solve(int i, int j, int flag){
    int &ans = dp[i][j][flag];

    if(ans != -1){
        return ans;
    }

    if(i > j){
        return 0;
    }

    ans = inf;

    int nxt = i;
    int carry = 0;
    int past = i;

    while(match[nxt] != nxt && match[nxt] <= j){
        past = nxt;
        nxt = match[nxt];

        ans = min(ans, solve(i + 1, nxt - 1, 1) + solve(nxt, j, 0) + flag);
    }

    ans = min(ans, solve(i + 1, j, 1) + flag);

    // ans++;
    assert(ans >= 0LL && ans != inf);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);
    memset(carry, -1, sizeof carry);

    int n;
    string s;

    cin >> n;
    cin >> s;

    for(int i = 0 ; i < s.length() ; i++){
        s[i] -= 'a';

        if(carry[s[i]] == -1){
            carry[s[i]] = i;
        }

        match[carry[s[i]]] = i;
        match[i] = i;

        carry[s[i]] = i;
    }

    // for(int i = 0 ; i < s.length() ; i++){
    //     cout << match[i] + 1 << " <-- " << i + 1 << endl;
    // }

    cout << solve(0, n - 1, 1) << endl;

    return 0;
}