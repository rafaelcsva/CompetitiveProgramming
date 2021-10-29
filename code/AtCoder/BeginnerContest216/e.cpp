#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll a[N];
priority_queue< pair< ll, ll > > pq;

int main(){
    int n;
    ll k;

    scanf("%d %lld", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);

        pq.push({a[i], 1});
    }

    pq.push({0LL,0LL});

    ll ans = 0LL;

    while(!pq.empty() && k){
        auto u = pq.top();
        pq.pop();

        if(u.first == 0LL){
            break;
        }

        ll sz = u.second;

        while(pq.top().first == u.first){
            sz += pq.top().second;
            pq.pop();
        }

        ll e = min(k, sz * (u.first - pq.top().first));
        ll x = e / sz;
        ll r = e % sz;

        ll s = (((2LL * u.first - x + 1LL) * x) / 2LL) * sz;
        ans += s;
        ans += r * (u.first - x);

        k -= e;

        // printf("%lld %lld %lld %lld %lld %lld\n", u, sz, ans, k, r, s);
        auto uu = pq.top();
        pq.pop();
        uu.second += sz;
        pq.push(uu);
    }

    printf("%lld\n", ans);

    return 0;
}