#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 22;
ll fat[N];
ll cnt[N];
ll cnt0[N];
int n;

ll solve(int u, ll pref = 0LL){
    if(u == n + 1){
        return 1LL;
    }

    ll tot = pref + cnt[u];

    return tot * solve(u + 1, tot - 1LL); 
}

int main(){
    fat[0] = 1LL;

    for(ll i = 1LL ; i < N ; i++){
        fat[i] = i * fat[i - 1];
    }

    int t;

    scanf("%d", &t);

    while(t--){
        ll ki;

        scanf("%llu", &ki);

        ll d = 2LL;
        n = 0;

        while(ki){
            cnt0[ki % d]++;
            cnt[max(ki % d, 1LL)]++;
            // printf("%lld %lld %llu\n", ki, ki % d, cnt[max(ki % d, 1ULL)]);
            ki /= d;
            d++;
            n++;
        }

        ll r = solve(1);

        // printf("bef = %lld\n", r);

        for(int i = 0 ; i < N ; i++){
            r /= fat[cnt0[i]];
        }
        // printf("now %lld\n", r);
        if(cnt0[0] >= 1){
            cnt0[0]--;
            cnt[1]--;
            n--;

            ll ret = solve(1);
            
            for(int i = 0 ; i < N ; i++){
                ret /= fat[cnt0[i]];
            }
            
            r -= ret;
        }

        printf("%lld\n", r - 1);

        for(int i = 0 ; i < N ; i++){
            cnt[i] = 0;
            cnt0[i] = 0;
        }
    }

    return 0;
}