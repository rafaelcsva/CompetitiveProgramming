#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long   ll;
 
const int N = int(2e5) + 10;
ll a[N];
map< ll, ll > cnt;

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main(){
    int n;
 
    scanf("%d", &n);
 
    __int128 sum = 0LL;
    __int128 ans = 0LL;
 
    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
 
        ll tsum = sum - (a[i] - 1LL) * cnt[a[i] - 1] - (a[i] + 1LL) * cnt[a[i] + 1];
        ll p = i - cnt[a[i] - 1] - cnt[a[i] + 1];
 
        ans += __int128(a[i] * p - tsum);
 
        cnt[a[i]]++;
        sum += a[i];
    }
 
    print(ans);
    printf("\n");
 
    return 0;
}