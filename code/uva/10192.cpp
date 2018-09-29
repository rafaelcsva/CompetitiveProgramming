//05, 08, 2018, 11:17:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

string s, t;
const int N = 110;
int dp[N][N];
int used[N][N];
int test = 1;
int n, m;

int solve(int i, int j){
    if(i >= n || j >= m){
        return 0;
    }

    int &ans = dp[i][j];

    if(used[i][j] == test){
        return ans;
    }

    used[i][j] = test;
    ans = 0;

    if(s[i] == t[j]){
        ans = solve(i + 1, j + 1) + 1;
    }else{
        ans = max(solve(i + 1, j), solve(i, j + 1));
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        getline(cin, s);

        if(s == "#")
            break;

        getline(cin, t);
        
        n = s.length();
        m = t.length();

        cout << "Case #" << test << ": " << "you can visit at most " << solve(0, 0) << " cities." << endl;
        test++;
    }

    return 0;
}