#include <bits/stdc++.h>

using namespace std;

map< string, bool > mark;

int main(){
    int n;

    cin >> n;

    bool frag = false;

    for(int i = 0 ; i < n ; i++){
        string s, t;

        cin >> s >> t;

        s = s + "*" + t;

        if(mark[s]){
            frag = true;
        }

        mark[s] = true;
    }

    if(frag){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

    return 0;
}