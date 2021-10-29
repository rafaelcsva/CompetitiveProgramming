#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    string s, t;

    cin >> q;

    while(q--){
        cin >> s >> t;
        int n = s.length();
        int m = t.length();
        int l = n * (m / __gcd(n, m));
        string ts = s;

        while(ts.length() < l){
            for(int i = 0 ; i < s.length() ; i++){
                ts.push_back(s[i]);
            }
        }
        string tt = t;
        while(tt.length() < l){
            for(int i = 0 ; i < t.length() ; i++){
                tt.push_back(t[i]);
            }
        }

        if(ts != tt){
            cout << -1 << endl;
        }else{
            cout << ts << endl;
        }
    }

    return 0;
}