#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll a[N];
const ll mod = ll(998244353LL);

// ll sum(int m, int n){
//     ll mx = -1;
//     ll mn = -1;
//     for(int j = 0 ; j < n ; j++){
//         int e = 1 << j;

//         if(m & e){
//             if(mx == -1){
//                 mx = a[j];
//                 mn = a[j];
//             }else{
//                 mx = max(mx, a[j]);
//                 mn = min(mn, a[j]);
//             }
//         }
//     }

//     return (mx * mn) % mod;
// }

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
    }

    // ll tmp = 0LL;

    // for(int m = 1 ; m < (1 << n) ; m++){
    //     tmp = (tmp + sum(m, n)) % mod;
    // }

    // printf("tmp = %lld\n", tmp);

    sort(a, a + n);

    ll sum = 0LL;
    ll ans = 0LL;

    for(int i = 0 ; i < n ; i++){
        // printf("%lld adds %lld\n", a[i], ((a[i] * sum) % mod + a[i] * a[i]));
        ans = (ans + ((a[i] * sum) % mod + a[i] * a[i]) % mod) % mod;
        sum = (sum * 2LL + a[i]) % mod;
    }

    printf("%lld\n", ans);

    return 0;
}