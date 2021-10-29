#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        ll a, b;

        scanf("%lld %lld", &a, &b);

        ll st = 9LL;
        ll cnt = 0LL;

        while(st <= b){
            cnt++;
            st = st * 10LL + 9LL;
        }

        printf("%lld\n", a * cnt);
    }

    return 0;
}