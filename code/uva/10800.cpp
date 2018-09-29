//23, 07, 2018, 15:40:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<pii, char>mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        string s;

        cin >> s;

        int i = 0, j = 2, mni = 0, mxi = 0;

        for(int k = 0 ; k < s.length() ; k++){
            
            if(s[k] == 'R'){

                mp[{i, j}] = '/';
                mxi = max(mxi, i);
                
                i++;
                
            }else if(s[k] == 'C'){
                mxi = max(mxi, i);
                mp[{i, j}] = '_';
            }else{
                if(k)
                    i--;
                mp[{i, j}] = '\\';
                
                mni = min(mni, i);
            }

            j++;
        }
        
        cout << "Case #" << test << ":" << endl;

        for(int l = mxi ; l >= mni ; l--){
            cout << "|";

            string s = "";
            
            for(int p = 1 ; p < j ; p++){
                if(mp[{l, p}]){
                    cout << s + mp[{l, p}];
                    s = "";
                }else{
                    s += ' ';
                }
            }

            cout << endl;
        }
        cout << '+';
        for(int i = 1 ; i <= j ; i++){
            cout << '-';
        }
        cout << endl << endl;

        mp.clear();
    }

    return 0;
}