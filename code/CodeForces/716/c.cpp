#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    vector< ll > ans, resp;
    ll pt = 1LL;

    ll n;
    scanf("%lld", &n);

    ans.push_back(1LL);
    
    ll prod = 1LL;
    pt = 1LL;

    for(ll i = 2 ; i < n ; i++){
        if(__gcd(n, i) == 1LL){
            prod = (prod * i) % n;
            ans.push_back(i);

            if(prod == 1LL){
                pt = i;
            }
        }
    }

    for(auto u: ans){
        resp.push_back(u);
        if(u == pt){
            break;
        }
    }

    printf("%lu\n", resp.size());

    for(auto u: resp){
        printf("%lld ", u);
    }
    printf("\n");

    return 0;
}