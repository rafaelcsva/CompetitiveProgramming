#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = 1000;
string s;
ll d;

int main (){
    int t;
    int test = 1;
    
    cin >> t;

    while(t--){
        cin >> d >> s;

        ll swp = 0LL;
        bool ok = false;

        for(int i = 0 ; i < N ; i++){
            ll pot = 1LL;
            ll boom = 0LL;

            for(int j = 0 ; j < s.length() ; j++){
                if(s[j] == 'C'){
                    pot *= 2LL;
                }else{
                    boom += pot;
                }
            }

            if(boom <= d){
                ok = true;
                break;
            }

            for(int j = s.length() - 1 ; j >= 1 ; j--){
                if(s[j] == 'S' && s[j - 1] == 'C'){
                    swap(s[j], s[j - 1]);
                    swp++;
                }
            }
        }

        cout << "Case #" << test++ << ": ";
         
        if(ok){
            cout << swp << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}