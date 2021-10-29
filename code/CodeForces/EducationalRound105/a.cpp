#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;

    vector< int > mp[300];

    mp['A'] = {-1, 1};
    mp['B'] = {-1, 1};
    mp['C'] = {-1, 1};
    
    for(int i = 0 ; i < n ; i++){
        string s;

        cin >> s;
        bool ok = false;

        for(int a = 0 ; a < 2 ; a++){
            for(int b = 0 ; b < 2 ; b++){
                for(int c = 0 ; c < 2 ; c++){
                    int sum = 0;

                    for(int i = 0 ; i < s.length() ; i++){
                        char d = s[i];
                        if(d == 'A'){
                            sum += mp[d][a];
                        }else if(d == 'B'){
                            sum += mp[d][b];
                        }else{
                            sum += mp[d][c];
                        }

                        if(sum < 0){
                            break;
                        }
                    }

                    if(sum == 0){
                        ok = true;
                    }
                }
            }
        }

        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}