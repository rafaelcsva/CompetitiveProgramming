#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        ll sum = 0LL;

        for(int i = 0 ; i < n ; i++){
            ll ai;

            scanf("%lld", &ai);

            sum += ai;
        }

        ll r = sum % ll(n);

        ll re = n - r;

        printf("%lld\n", r * re);
    }

    return 0;
}