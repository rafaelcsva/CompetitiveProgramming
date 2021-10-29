#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll mod = ll(1e9) + 7LL;

int main(){
    int n;

    scanf("%d", &n);

    set< ll > st;

    st.insert(0LL);

    for(int i = 0 ; i < n ; i++){
        ll xi;

        scanf("%lld", &xi);

        st.insert(xi);
    }

    ll last = 0LL;
    ll ans = 1LL;

    for(auto u: st){
        ans = (ans * (u - last + 1LL)) % mod;
        last = u;
    }

    printf("%lld\n", ans);

    return 0;
}