#include <bits/stdc++.h>

using namespace std;

const int N = 510, K = 30;
string dp[N][K];
string s;
int used[N][K];
int test;
int n, k;

string solve(int i, int letter){
    if(i == n){
        return "";
    }

    int &us = used[i][letter];
    string &ans = dp[i][letter];

    if(us == test){
        return ans;
    }

    ans = "";
    us = test;
    int min_letter = k;

    if(i != n - 1){
        min_letter = s[i + 1] - 'a';
    }

    string pt = "";
    int adv = (letter + 1) % k;
    int ret = letter == 0 ? k - 1 : letter - 1;
    int res = min({adv, ret, s[i] - 'a'});

    if(res <= min_letter){
        min_letter = res;
        pt = solve(i + 1, s[i + 1] - 'a');
    }else{
        pt = solve(i + 1, s[i] - 'a');
    }

    // cout << char(min_letter + 'a') << " on " << i << " gives " << pt <<" , " << string(1, min_letter + 'a') << endl;
    ans = string(1, min_letter + 'a') + pt;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(test = 1 ; test <= t ; test++){
        cin >> n >> k;
    
        cin >> s;

        auto ans = solve(0, s[0] - 'a');

        cout << ans << endl;
    }

    return 0;
}