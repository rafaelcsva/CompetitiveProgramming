//16, 05, 2018, 13:26:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int sum(ll n){
    int d = 0;

    while(n){
        d += n % 10LL;
        n /= 10LL;
    }

    return d;
}

int sum_factors(ll n){
    ll tmp = n;
    int d = 0;

    for(ll i = 2LL ; i * i <= n ; i++){
        if(tmp % i == 0LL){
            while(tmp % i == 0){
                tmp /= i;
                d += sum(i);
            }
        }
    }

    if(tmp == n){
        return -1;
    }
    
    if(tmp != 1){
        d += sum(tmp);
    }

    return d;
}

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin >> t;

    while(t--){
        ll n;

        cin >> n;
        
        while(sum_factors(++n) != sum(n));

        cout << n << endl;
    }

    return 0;
}