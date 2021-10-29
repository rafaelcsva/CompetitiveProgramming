#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll dp[N][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        ll ans = 0LL;

        for(int i = 0 ; i < s.length() ; i++){
            dp[i][0] = dp[i][1] = 0LL;

            if(s[i] == '?'){
                dp[i][0] = dp[i][1] = 1LL;

                if(i){
                    dp[i][0] += dp[i - 1][1];
                    dp[i][1] += dp[i - 1][0];
                }
            }else if(s[i] == '1'){
                dp[i][1] = 1LL;

                if(i){
                    dp[i][1] += dp[i - 1][0];
                }
            }else{
                dp[i][0] = 1LL;
                if(i){
                    dp[i][0] += dp[i - 1][1];
                }
            }

            ans += max(dp[i][0], dp[i][1]);
            // printf("adds %lld [%lld, %lld]\n", dp[i][0] + dp[i][1], dp[i][0], dp[i][1]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}