#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll cnt[N];
int a[N], b[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &b[i]);
    }

    ll ans = 0LL;

    for(int i = 1 ; i <= n ; i++){
        int ci;

        scanf("%d", &ci);

        ans += cnt[b[ci]];
    }

    printf("%lld\n", ans);

    return 0;
}