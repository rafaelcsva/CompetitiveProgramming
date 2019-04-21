//01, 04, 2019, 17:35:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    int z = alphabet.length();

    while(t--){
        string s;

        cin >> s;

        bool ok = true;

        for(int i = 0 ; i < alphabet.length() ; i++){
            if(alphabet[i] == s[0]){
                for(int j = 0 ; j < s.length() ; j++){
                    if(s[j] != alphabet[(i + j) % z]){
                        ok = false;
                        break;
                    }
                }

                break;
            }
        }

        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}