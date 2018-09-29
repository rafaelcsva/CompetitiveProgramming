#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int c[N];
const int L = 10;

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    bool flag = false;

    while(t--){
        string s;

        int i = 0;
        
        int m = 0;

        for(int i = 0 ; i < L ; i++){
            cin >> s;

            if(i){
                m = s.length();
                
                for(int j = 1 ; j < s.length() ; j++){
                    if(s[j] != '/'){
                        c[j - 1] |= (1 << (i - 1));
                    }
                }
            }
        }

        for(int i = 0 ; i < m - 2 ; i++){
            cout << char(c[i]);
        }

        cout << endl;

        memset(c, 0, sizeof c);
        
    }

    return 0;
}