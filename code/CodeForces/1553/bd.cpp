#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        string s, t;

        cin >> s >> t;

        if(s == t){
            cout << "YES\n";
            continue;
        }else if(s.size() <= t.size()){
            cout << "NO1\n";
            continue;
        }
        int j = t.size() - 1;
        int flag = 0;

        for(int i = s.size()  -1 ; i >= 0 ; i--){
            if(s[i] == t[j]){
                j--;
                if(j == -1){
                    flag = 1;
                    break;
                }
            }else{
                i--;
            }
        }

        if(flag == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO2" << endl;
        }
    }
    return 0;
}