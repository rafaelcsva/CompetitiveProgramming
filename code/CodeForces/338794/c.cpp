#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll dp[N];
const ll mod = ll(1e9) + 7LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    dp[0] = 1LL;

    for(int i = 1 ; i <= s.length() ; i++){
        if(s[i - 1] == 'w' || s[i - 1] == 'm'){
            cout << "0\n";
            return 0;
        }

        dp[i] = dp[i - 1];

        if(i > 1 && (s[i - 1] == 'n' && s[i - 2] == 'n' || s[i - 1] == 'u' && s[i - 2] == 'u')){
            dp[i] += dp[i - 2];

            if(dp[i] >= mod){
                dp[i] -= mod;
            }
        }
    }

    cout << dp[s.length()] << "\n";

    return 0;
}
