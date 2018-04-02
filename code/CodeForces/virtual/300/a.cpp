#include <bits/stdc++.h>

using namespace std;

int n;
string c, s;

bool can(int i, int j){
    if(n - (j - i + 1) != c.length()){
        return false;
    }
    int pos = 0;
    int k = 0;

    while(k < n){
        if(k == i){
            k = j + 1;
            continue;
        }

        if(s[k] != c[pos]){
            return false;
        }

        k++, pos++;
    }

    return true;
}
int main (){
    c = "CODEFORCES";

    cin >> s;
    n = s.length();

    for(int i = 0 ; i < n; i++){
        for(int j = i ; j < n ; j++){
            if(can(i, j)){
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}