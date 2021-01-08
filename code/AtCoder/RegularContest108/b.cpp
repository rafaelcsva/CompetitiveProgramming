#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;

    cin >> n >> s;

    string p = "";

    for(int i = 0 ; i < n ; i++){
        p.push_back(s[i]);
        int sz = p.length();
            
        if(sz >= 3){
            string tmp = "";
            for(int d = sz - 3 ; d < sz ; d++){
                tmp.push_back(p[d]);
            }

            if(tmp == "fox"){
                for(int d = 0 ; d < 3 ; d++){
                    p.pop_back();
                }
            }
        }
    }

    printf("%ld\n", p.length());

    return 0;
}