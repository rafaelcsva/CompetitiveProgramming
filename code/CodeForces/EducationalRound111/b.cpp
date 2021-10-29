#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n, a, b;

        cin >> n >> a >> b;

        string s;

        cin >> s;

        int ans = n * a;

        if(b >= 0){
            ans += n * b; 
        }else{
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            cnt[s[0] - '0']++;
            for(int i = 1 ; i < n ; i++){
                if(s[i] != s[i - 1]){
                    cnt[s[i] - '0']++;
                }
            }

            int mn = min(cnt[0], cnt[1]);

            ans += mn * b + b;
        }

        cout << ans << endl;
    }

    return 0;
}