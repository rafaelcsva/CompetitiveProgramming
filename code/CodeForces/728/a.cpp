#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(1e5) + 10;
ll d[N];
ll v[N];
ll ans[N];
ll a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        sort(a, a + n);

        int pt = 0;
        ll tot = 0LL;

        for(int i = 1 ; i < n ; i++){
            while(a[v[pt]] > a[i]){
                pt--;
            }
            v[++pt] = i;
            ll d = a[v[pt]] - a[v[pt - 1]];

            ans[v[pt]] = ans[v[pt - 1]] + d * ll(pt);
            // printf("%d is on %d with %lld gives %lld\n", i, pt, d, ans[v[pt]]);
            
            tot += d - ans[v[pt]];
        }

        printf("%lld\n", tot);
    }

    return 0;
}