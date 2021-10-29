#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = int(3e5) + 10;
const ll MX = ll(1e18);
ll pref[N], pref1[N];
int a[N];
ll hhash[N];
int n;

ll solve(){
    for(int i = 1 ; i <= n ; i++){
        pref1[i] = hhash[a[i]] ^ pref1[i - 1];
    }

    ll ans = 0LL;
    int l1 = -1;
    int mx = 1;

    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 1){
            l1 = i;
            mx = 1;
            continue;
        }
        if(l1 == -1){
            continue;
        }

        if(a[i] > mx){
            mx = a[i];
        }

        int pos = i - mx;

        if(pos < l1 && pos >= 0){
            ll val = pref1[i] ^ pref1[pos];

            if(val == pref[mx]){
                // printf("%d - %d | mx = %d\n", pos + 1, i, mx);
                ans++;
            }
        }
    }

    return ans;
}

int main(){
    scanf("%d", &n);

    ll cnt1 = 0LL;

    for(int i = 1 ; i <= n ; i++){
        hhash[i] = rng() % MX;
        pref[i] = hhash[i] ^ pref[i - 1];
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        cnt1 += (a[i] == 1);
    }

    ll ans1 = solve();
    reverse(a + 1, a + 1 + n);
    ll ans2 = solve();

    printf("%lld\n", ans1 + ans2 + cnt1);

    return 0;
}