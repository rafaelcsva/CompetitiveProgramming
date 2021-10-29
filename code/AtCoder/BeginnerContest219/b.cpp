#include <bits/stdc++.h>

using namespace std;

int main(){
    string s[3];
    string t;

    for(int i = 0 ; i < 3 ; i++){
        cin >> s[i];
    }

    cin >> t;

    string ans = "";

    for(auto u: t){
        ans = ans + s[u - '1'];
    }

    cout << ans << "\n";

    return 0;
}