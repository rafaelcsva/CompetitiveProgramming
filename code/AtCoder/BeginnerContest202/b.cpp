#include <bits/stdc++.h>

using namespace std;

int mp[1000];

int main(){
    mp['0'] = '0';
    mp['1'] = '1';
    mp['6'] = '9';
    mp['8'] = '8';
    mp['9'] = '6';

    string s;

    cin >> s;

    reverse(s.begin(), s.end());

    for(auto &c: s){
        c = mp[c];
    }

    cout << s << endl;

    return 0;
}