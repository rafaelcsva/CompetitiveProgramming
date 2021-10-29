#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n;

    scanf("%lld", &n);

    int k = 0;
    ll u = 1LL;

    while((u << 1LL) <= n){
        u <<= 1LL;
        k++;
    }

    printf("%d\n", k);

    return 0;
}