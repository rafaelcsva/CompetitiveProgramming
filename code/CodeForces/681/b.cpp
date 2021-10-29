#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    cin >> t;

    while(t--){
        ll a, b;

        cin >> a >> b;

        ll last = -1LL;

        string s;

        cin >> s;

        ll ans = 0LL;
    
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '1'){
                if(last == -1){
                    // cout << "+" << a << "\n";
                    ans += a;
                }else{
                    // cout << "+" << min(a, ll(i - last) * b) << "\n";
                    ans += min(a, ll(i - last - 1) * b);
                }

                last = i;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}