//09, 08, 2018, 16:52:53 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;

    scanf("%lld", &n);

    bool is_all_nine = true;

    ll tmp = n;
    int digits = 0;
    ll p = 0LL;
    ll last = 0LL;

    while(tmp){
        p = p * 10LL + 1LL;
        digits++;

        if(tmp % 10LL != 9LL){
            is_all_nine = false;
        }

        last = tmp % 10LL;
        tmp /= 10LL;
    }

    p *= 9LL;

    if(is_all_nine){
        printf("%lld\n", (n - 1LL) / 2LL);
    }else{
        ll need = p - n;
        printf("%lld %lld\n", p, need);

        if(need <= n){
            printf("%lld\n", (n - need + 1LL) / 2LL);
        }else{
            p /= 10LL;

            printf("%lld\n", ((p + 1LL) * last) / 2LL - 1);
        }
    }

    return 0;
}