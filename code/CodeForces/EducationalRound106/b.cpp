#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        bool ver1 = false;
        bool flag = true;
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] == s[i - 1]){
                if(s[i] == '1'){
                    ver1 = true;
                }else if(ver1){
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}