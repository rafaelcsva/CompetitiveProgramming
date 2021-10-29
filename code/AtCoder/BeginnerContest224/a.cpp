#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin >> s;

    int n = s.length() - 1;

    if(s[n] == 'r'){
        cout << "er\n";
    }else{
        cout << "ist\n";
    }

    return 0;
}