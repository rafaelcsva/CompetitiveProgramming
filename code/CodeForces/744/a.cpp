#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        int cnta = 0, cntb = 0, cntc = 0;

        for(auto u: s){
            if(u == 'A'){
                cnta++;
            }else if(u == 'B'){
                cntb++;
            }else{
                cntc++;
            }
        }

        if(cntb == cnta + cntc){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}