//21, 07, 2018, 09:57:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;

    cin >> s >> t;

    int n = s.length();

    for(int i = 0 ; i < n ; i++){
        bool ok = true;

        for(int j = 0 ; j < n ; j++){
            int p = (i + j) % n;

            if(s[p] != t[j]){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    
    return 0;
}