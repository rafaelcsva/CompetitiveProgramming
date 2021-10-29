#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll n, k;

        scanf("%lld %lld", &n, &k);

        ll ans = 0LL;

        while(n != 0){
            if(n % k == 0){
                n /= k;
                ans++;
            }else{
                ll r = n % k;
                ans += r;
                n -= r;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}