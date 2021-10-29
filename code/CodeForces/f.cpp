#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

int main(){
    ll n;

    scanf("%lld", &n);

    ll tn = n;
    ll a = -1LL;
    ll b = -1LL;

    for(ll i = 2LL ; i * i <= n ; i++){
        if(n % i == 0LL){
            a = 1LL;

            while(n % i == 0LL){
                a *= i;
                n /= i;
            }

            break;
        }
    }
    // printf("%lld %lld\n", a, n);
    if(a == -1LL || n == 1LL){
        printf("NO\n");
    }else{
        b = n;

        if(a < b){
            swap(a, b);
        }

        tn--;

        for(ll k = 1LL ; k < b && tn > a * k ; k++){
            ll rest = tn - a * k;
            ll k_ = rest / b;

            if(rest % b == 0LL && k_ < a){

                printf("YES\n2\n");
                printf("%lld %lld\n", k_, a);
                printf("%lld %lld\n", k, b);

                return 0;
            }
        }

        assert(false);
    }

    return 0;
}