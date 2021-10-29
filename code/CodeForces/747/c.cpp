#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;
        char c;

        cin >> n >> c;
        string s;

        cin >> s;

        bool ok = false;

        for(int i = 0 ; i < n ; i++){
            if(s[i] != c){
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << 0 << "\n";
            continue;
        }

        bool frag = false;

        for(int i = 1 ; i <= n ; i++){
            frag = true;    

            for(int j = i ; j <= n ; j += i){
                if(s[j - 1] != c){
                    frag = false;
                    break;
                }
            }

            if(frag){
                cout << 1 << "\n" << i << "\n";
                break;
            }
        }
        if(!frag)
            cout << 2 << "\n" << n - 1 << " " << n << "\n";
    }

    return 0;
}