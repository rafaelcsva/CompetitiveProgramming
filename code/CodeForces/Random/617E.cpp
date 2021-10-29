#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int M = int(5e6);
const int N = int(1e5) + 10;
ll pref_cnt[M];
ll suf_cnt[M];
int pref[N];
int suf[N];
int l[N], r[N];
int a[N];
ll ans[N];
int block_size = 317;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

Query q[N];

int main(){
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        pref[i] = a[i] ^ pref[i - 1];
    }

    for(int i = n ; i >= 1 ; i--){
        suf[i] = a[i] ^ suf[i + 1];
    }

    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].idx = i;
    }

    sort(q + 1, q + 1 + m);

    pref_cnt[pref[1]]++;
    suf_cnt[suf[1]]++;
    ll cur = (a[1] == k);
    int st = 1, en = 1;

    // for(int i = 1 ; i <= n ; i++){
    //     printf("%d ", suf[i]);
    // }
    // printf("\n");
    for(int i = 1 ; i <= m ; i++){
        while(st > q[i].l){
            st--;
            pref_cnt[pref[st]]++;
            suf_cnt[suf[st]]++;
            cur += pref_cnt[k ^ pref[st - 1]];
        }

        while(en < q[i].r){
            en++;
            pref_cnt[pref[en]]++;
            suf_cnt[suf[en]]++;
            cur += suf_cnt[k ^ suf[en + 1]];
        }

        while(st < q[i].l){
            cur -= pref_cnt[k ^ pref[st - 1]];
            pref_cnt[pref[st]]--;
            suf_cnt[suf[st]]--;
            st++;
        }

        while(en > q[i].r){
            cur -= suf_cnt[k ^ suf[en + 1]];
            pref_cnt[pref[en]]--;
            suf_cnt[suf[en]]--;
            en--;
        }

        ans[q[i].idx] = cur;
    }

    for(int i = 1 ; i <= m ; i++){
        printf("%lld\n", ans[i]);
    }

    return 0;
}