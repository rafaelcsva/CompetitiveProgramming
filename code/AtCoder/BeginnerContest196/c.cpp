#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n;
    
    scanf("%lld", &n);

    ll p = 1LL;
    ll cnt = 0LL;

    for(ll i = 1LL ; ; i++){
        if(i >= p){
            p *= 10LL;
        }

        if(i * p + i > n){
            break;
        }

        cnt++;
    }

    printf("%lld\n", cnt);

    return 0;
}