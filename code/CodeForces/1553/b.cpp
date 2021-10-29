#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s, t;

        cin >> s >> t;
    
        bool can = false;

        for(int i = 0 ; i < s.length() ; i++){
            for(int j = i ; j < s.length() ; j++){
                if(s[j] != t[j - i]){
                    break;
                }

                int o = j - i + 1;
                int e = j - 1;
                while(o < t.length() && e >= 0){
                    if(t[o] != s[e]){
                        break;
                    }

                    o++, e--;
                }

                if(o == t.length()){
                    can = true;
                    break;
                }
            }
            if(can) break;
        }

        if(can){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}