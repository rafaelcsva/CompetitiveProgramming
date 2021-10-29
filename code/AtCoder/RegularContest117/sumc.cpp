#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll sum = 0LL;

    for(ll i = ll(4e5) ; i >= 0 ; i -= 20){
        sum += i;
    }

    cout << sum << "\n";

    return 0;
}