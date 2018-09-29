//26, 07, 2018, 10:01:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

string s;
bool fit(string &p, int pos){
    int n = p.length();

    for(int i = 0 ; pos < s.length() ; pos++, i++){
        i %= n;

        if(p[i] != s[pos]){
            return false;
        }    
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        cin >> s;
        
        string p = "";
        bool find = false;

        for(int i = 0 ; i < s.length() ; i++){
            p += s[i];

            if(fit(p, i + 1)){
                break;
            }
        }

        int n = p.length();
        int st = s.length() % n;
        
        for(int i = 0 ; i < 8 ; i++, st++){
            cout << p[st % n];
        }

        cout << "..." << endl;
    }

    return 0;
}