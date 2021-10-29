#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(2e5) + 10;
ll h[N];
const ll inf = ll(2e18);
int n;
ll sum;

ll solve(int id, ll x, ll y){
    if(id < 0 || id >= n){
        return inf;
    }

    ll rest = sum - h[id];

    ll ans = 0LL;

    ans += max(0LL, y - rest);

    ans += max(0LL, x - h[id]);

    return ans;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &h[i]);
        sum += h[i];
    }

    sort(h, h + n);

    int m;

    scanf("%d", &m);

    for(int i = 0 ; i < m ; i++){
        ll x, y;

        scanf("%lld %lld", &x, &y);

        int hid = lower_bound(h, h + n, x) - h;

        ll ans = inf;

        ans = min(solve(hid, x, y), solve(hid - 1, x, y));

        printf("%lld\n", ans);
    }

    return 0;
}