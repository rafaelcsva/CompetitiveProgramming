//15, 08, 2018, 09:50:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin >> s;

    int diff = 0;
    
    for(int i = 0, j = s.length() - 1 ; i < s.length() / 2 ; i++, j--){
        if(s[i] != s[j]){
            diff++;
        }
    }

    if(diff == 1){
        cout << "YES" << endl;
    }else{
        if(diff == 0){
            if(s.length() & 1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}