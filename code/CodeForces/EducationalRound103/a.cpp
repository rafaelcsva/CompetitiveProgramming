#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        ll x = (n + k - 1LL) / k;

        k *= x;
        ll el = (k / n) + ((k % n) ? 1LL : 0LL);

        printf("%lld\n", el);
    }
}