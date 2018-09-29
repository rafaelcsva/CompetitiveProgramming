//18, 08, 2018, 09:12:15 Rafaelcs cpp
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
    ll k;

    cin >> s >> k;

    for(int i = 0 ; i < s.length() ; i++){
        if(k == 1){
            cout << s[i] << endl;
            return 0;
        }else if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }else{
            k--;
        }
    }

    return 0;
}