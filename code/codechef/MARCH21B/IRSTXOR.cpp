#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t-- >= 1){
        ll c;

        // c = t + 1;
        scanf("%lld", &c);

        ll j;
        for(j = 1LL ; j <= c ; j *= 2LL);

        // ll ans1 = 0;

        // for(int a = 0 ; a < j ; a++){
        //     ll b = a ^ c;

        //     ans1 = max(ans1, (a * b));
        // }

        j >>= 1;
        ll a = j | ((j - 1) ^ (c ^ j));
        ll b = c ^ a;

        // assert(ans1 == a * b);
        printf("%lld\n", a * b);
    }

    return 0;
}