//06, 08, 2018, 17:01:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 210;
ll dp[N][N];
int used[N][N];
int test;
string s;
int n;

ll sum_slice(int i, int j){
    ll number = 0LL;

    for(int k = i ; k <= j ; k++){
        number = number * 10LL + int(s[k] - '0');
    }

    return number;
}

ll solve(int p, int st){
    if(p == n){
        return sum_slice(st, p - 1);
    }

    ll &ans = dp[p][st];

    if(used[p][st] == test){
        return ans;
    }

    used[p][st] = test;

    ans = 0LL;

    ll num = sum_slice(st, min(p + 1, n - 1));

    if(num <= INT_MAX){
        ans = solve(p + 1, st);
    }
    
    ans = max(sum_slice(st, p) + solve(p + 1, p + 1), ans);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(test = 1 ; test <= t ; test++){
        cin >> s;

        n = s.length();

        cout << solve(0, 0) << endl;
    }

    return 0;
}