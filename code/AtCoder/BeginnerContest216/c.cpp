#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll x;

    cin >> x;

    for(ll d = 59LL ; d >= 0LL ; d--){
        cout << "B";

        ll e = 1LL << d;
    
        if(x & e){
            cout << "A";
        }
    }

    cout << "\n";

    return 0;
}