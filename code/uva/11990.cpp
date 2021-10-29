#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
ll a[N];
vector< ll > sq[N];
vector< ll > sq1[N];
int idx[N];
int SQ;

int query1(int pos, int v){
    int sum = 0;
    int st = 0;

    int block = (pos - 1) / SQ;

    int tmp = 0;
    int sig = 0;

    int lf = 0, rg = 0;
    for(auto u: sq1[block]){
        if(u == v){
            sig = 1;
        }
        if(sig){
            sum += (u < v);
            // lf += (u < v);
        }else{
            sum += (u > v);
            // lf += (u > v);
            tmp++;
        }
    }

    auto u = lower_bound(sq[block].begin(), sq[block].end(), v);
    sq[block].erase(u);
    sq1[block].erase(sq1[block].begin() + tmp);

    for(int i = 0 ; i < block ; i++){
        sum += sq[i].end() - upper_bound(sq[i].begin(), sq[i].end(), v);
        // lf += sq[i].end() - upper_bound(sq[i].begin(), sq[i].end(), v);
    }

    for(int i = block + 1 ; i < SQ ; i++){
        sum += lower_bound(sq[i].begin(), sq[i].end(), v) - sq[i].begin();
        // rg += lower_bound(sq[i].begin(), sq[i].end(), v) - sq[i].begin();
    }
    // printf("sz: %lu %d (%d, %d) | %d\n", sq[0].size() + sq[1].size(), sum, lf, rg, block);
    // for(int i = 0 ; i < SQ ; i++){
    //     for(auto u: sq1[i]){
    //         printf("%lld ", u);
    //     }
    // }
    // printf("\n");
    return sum;
}

ll bit[N];

int LSOne(int x){
    return x & (-x);
}

ll query(int x){
    ll sum = 0LL;

    while(x > 0LL){
        sum += bit[x];
        x -= LSOne(x);
    }

    return sum;
}

void update(int x){
    while(x < N){
        bit[x]++;
        x += LSOne(x);
    }
}

int main(){
    int n, m;
    ll ans = 0LL;

    while(scanf("%d %d", &n, &m) != EOF){
        SQ = sqrt(n) + 1;
        ll ans = 0LL;

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
            idx[a[i]] = i + 1;

            ans += query(n) - query(a[i]);
            update(a[i]);

            sq[i / SQ].push_back(a[i]);
            sq1[i / SQ].push_back(a[i]);
        }

        for(int i = 0 ; i < SQ ; i++){
            sort(sq[i].begin(), sq[i].end());
        }

        while(m--){
            int pos;

            scanf("%d", &pos);
            
            printf("%lld\n", ans);

            ans -= ll(query1(idx[pos], pos));
        }

        for(int i = 0 ; i < SQ ; i++){
            sq[i].clear();
            sq1[i].clear();
        }

        memset(bit, 0, sizeof bit);
    }

    return 0;
}