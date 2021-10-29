#include <bits/stdc++.h>

using namespace std;

int v[3];

int main(){
    int t;

    cin >> t;

    while(t--){
        int mx = 0;

        for(int i = 0 ; i < 3 ; i++){
            cin >> v[i];
            mx += v[i] - 1;
        }

        int m;

        cin >> m;

        sort(v, v + 3);

        int mn;
        
        if(v[2] <= v[0] + v[1]){
            mn = 0;
        }else{
            mn = v[2] - (v[0] + v[1]) - 1;
        }

        if(mn <= m && m <= mx){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}