//17, 07, 2018, 13:34:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int fit(ll v){
    ll m = 0;

    while(v){
        ll d = pow(v, 0.34);
        if(d * d * d > v){
            d--;
        }
        
        v -= d * d * d;
        m++;
    }

    return m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll m;

    cin >> m;

    int best_fit = 0;
    int block = 0;

    for(ll i = 1 ; i <= m ; i++){
        cout << "testing with " << i << endl;
        int f = fit(i);

        if(f >= best_fit){
            best_fit = f;
            block = i;
        }
    }

    cout << best_fit << ' ' << block << endl;

    return 0;
}