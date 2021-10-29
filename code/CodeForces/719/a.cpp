#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        string s;

        cin >> s;

        int mark[30];

        memset(mark, 0, sizeof mark);

        bool frag = false;

        char last = '$';
        for(auto c: s){
            if(c != last && mark[c - 'A']){
                // cout << "on " << c << endl;
                frag = true;
                break;
            }
            last = c;
            mark[c - 'A'] = 1;
        }

        if(frag){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }

    return 0;
}