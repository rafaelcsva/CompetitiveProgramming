//12, 11, 2018, 12:39:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    cin >> n;

    ll div = n;
    ll add = 0LL;
    
    for(ll i = 2LL ; i * i <= n ; i++){
        if(n % i == 0LL){
            div = min(div, i);
            div = min(div, n / i);
        }
    }

    
    if(div == n){
        cout << 1 << endl;
    }else{
        if(div == 2LL){
            cout << n / 2LL << endl;
        }else{
            add = 1LL;
            n -= div;

            cout << add + n / 2LL << endl;
        }
    }

    return 0;
}