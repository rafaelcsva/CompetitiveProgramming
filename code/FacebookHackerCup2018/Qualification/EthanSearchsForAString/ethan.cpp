//06, 07, 2018, 20:50:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

bool ok(string &s, int i, int j){
    while(max(i, j) < s.length()){
        if(s[i] != s[j]){
            return false;
        }

        i++, j++;
    }

    return true;
}

string solve(string &s){
    string r = "Impossible";

    if(s.length() <= 2){
        return r;
    }

    for(int i = 1 ; i < int(s.length()) - 1 ; i++){
        if(s[0] == s[i]){
            if(!ok(s, 1, i + 1)){
                r = s.substr(0, i);
                r += s;

                return r;
            }
        }
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        string s;

        cin >> s;

        cout << "Case #" << test << ": " << solve(s) << endl; 
    }
    
    return 0;
}