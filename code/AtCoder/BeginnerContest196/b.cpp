#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin >> s;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '.'){
            break;
        }

        cout << s[i];
    }

    cout << '\n';

    return 0;
}