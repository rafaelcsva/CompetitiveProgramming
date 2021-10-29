#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;
string tab[N];
int dp[N];
int n;

int dist(int a, int b){
    int cnt = 0;

    for(int d = 0 ; d < tab[a].length() ; d++){
        if(tab[a][d] == tab[b][d]){
            cnt++;
        }
    }

    return cnt;
}

int solve(int u){
    int &ans = dp[u];

    if(ans != -1){
        return ans;
    }

    ans = 0;

    for(int i = u + 1 ; i < min(u + 10, n) ; i++){
        if(i - u <= dist(i, u)){
            ans |= !solve(i);
        }
    }

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> tab[i];
    }

    string ans = "";

    for(int i = 0 ; i < n ; i++){
        if(solve(i)){
            ans.push_back('1');
        }else{
            ans.push_back('2');
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}