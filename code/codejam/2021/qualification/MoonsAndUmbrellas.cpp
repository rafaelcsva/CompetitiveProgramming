#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int dp[N][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int test = 1;

    cin >> t;

    while(t--){
        int x, y;
        string s;

        cin >> x >> y >> s;

        int n = int(s.length());

        for(int i = 1 ; i <= n ; i++){
            dp[i][1] = dp[i][0] = 100000;
            if(s[i - 1] == 'J'){
                dp[i][1] = min(i > 1 ? dp[i - 1][0] + x : 100000, dp[i - 1][1]);
            }else if(s[i - 1] == 'C'){
                dp[i][0] = min(i > 1 ? dp[i - 1][1] + y : 100000, dp[i - 1][0]);
            }else{
                dp[i][1] = min(i > 1 ? dp[i - 1][0] + x : 100000, dp[i - 1][1]);
                dp[i][0] = min(i > 1 ? dp[i - 1][1] + y : 100000, dp[i - 1][0]);
            }
        }

        cout << "Case #" << test++ << ": " << min(dp[n][1], dp[n][0]) << endl;
    }

    return 0;
}