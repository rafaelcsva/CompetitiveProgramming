//30, 12, 2018, 12:58:09 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

set< ll > values;

void process(ll div, ll n){
    ll nem = n / div;
    ll a1 = 1LL;
    ll an = a1 + (nem - 1LL) * div;

    values.insert(((a1 + an) * nem) / 2LL);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    cin >> n;

    for(ll div = 1LL ; div * div <= n ; div++){
        if(n % div == 0LL){
            process(div, n);
            process(n / div, n);
        }
    }
    
    for(set< ll >::iterator it = values.begin() ; it != values.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}