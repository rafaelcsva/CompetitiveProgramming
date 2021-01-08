#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll s, p;

    scanf("%lld %lld", &s, &p);

    for(ll d = 1LL ; d * d <= p ; d++){
        ll o = p / d;

        if(o + d == s){
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}