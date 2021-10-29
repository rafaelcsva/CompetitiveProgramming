#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    int t;

    cin >> t;

    while(t--){
        int px, py;

        cin >> px >> py;

        cin >> s;

        int x = 0, y = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'U'){
                y++;
            }else if(s[i] == 'D'){
                y--;
            }else if(s[i] == 'L'){
                x--;
            }else{
                x++;
            }
        }

        int d = px - x;
        int f = py - y;

        for(int i = 0 ;i < s.length() ; i++){
            if(f < 0 && s[i] == 'U'){
                f++;
            }else if(f > 0 && s[i] == 'D'){
                f--;
            }else if(d < 0 && s[i] == 'R'){
                d++;
            }else if(d > 0 && s[i] == 'L'){
                d--;
            }
        }

        if(!f && !d){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}