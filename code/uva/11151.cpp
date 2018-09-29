//06, 08, 2018, 16:42:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

string s;
int n;
const int N = 1010;
int dp[N][N];
int used[N][N];
int test = 1;

int solve(int i, int j){
        
    if(i > j){
        return 0;
    }

    int &ans = dp[i][j];

    if(used[i][j] == test){
        return ans;
    }

    used[i][j] = test;

    ans = 0;

    if(s[i] == s[j]){
        int add = 1;

        if(i != j)
            add++;

        ans = add + solve(i + 1, j - 1);
    }

    ans = max(ans, solve(i + 1, j));
    ans = max(ans, solve(i, j - 1));

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;
    cin.ignore();
    
    while(t--){
        getline(cin, s);

        n = s.length();

        cout << solve(0, n - 1) << endl;

        test++;
    }

    return 0;
}