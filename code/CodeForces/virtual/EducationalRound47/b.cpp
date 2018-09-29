//15, 07, 2018, 17:22:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<char, int>mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;

    cin >> s;

    int n = s.length();

    for(int i = 0 ; i < s.length() ; i++){
        mp[s[i]]++;
    }

    bool printed = false;

    for(int i = 0 ; i < s.length() ; i++){
        if(printed){
            if(s[i] != '1'){
                cout << s[i];
            }

            continue;
        }
        if(s[i] == '2'){
            while(mp['1']){
                cout << 1;
                mp['1']--;
            }
            cout << s[i];
            printed = true;
        }else if(s[i] == '0'){
            cout << s[i];
        }
    }

    while(mp['1']){
        cout << 1;
        mp['1']--;
    }

    cout << endl;

    return 0;
}