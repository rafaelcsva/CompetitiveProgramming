#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int n;

    scanf("%d", &n);

    ll dx1, dy1;
    ll dx2, dy2;

    scanf("%lld %lld", &dx1, &dy1);
    scanf("%lld %lld", &dx2, &dy2);

    dy1 = abs(dy1);
    dx1 = abs(dx1);
    dy2 = abs(dy2);
    dx2 = abs(dx2);

    ll g1 = __gcd(dx1, dx2);
    ll g2 = __gcd(dy1, dy2);

    if(g1 * g2 != n){
        printf("NO\n");
    }else{
        printf("YES\n");

        for(ll x = 0 ; x < g1 ; x++){
            for(ll y = 0 ; y < g2 ; y++){
                printf("%lld %lld\n", x, y);
            }
        }
    }

    return 0;
}