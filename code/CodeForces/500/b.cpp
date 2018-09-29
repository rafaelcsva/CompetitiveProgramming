//30, 07, 2018, 05:21:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<int, bool> mp, mp_e;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;

    cin >> n >> x;

    int mn = INF;

    for(int i = 0 ; i < n ; i++){
        int v;

        cin >> v;

        if(mp[v]){
            mn = 0;
        }
        
        if(mp[v & x]){
            mn = min(mn, 1);
        }
        
        if(mp_e[v]){
            mn = min(mn, 1);
        }

        if(mp_e[v & x]){
            mn = min(mn, 2);
        }

        mp[v] = true;
        mp_e[v & x] = true;
    }

    if(mn == INF){
        cout << "-1" << endl;
    }else{
        cout << mn << endl;
    }

    return 0;
}