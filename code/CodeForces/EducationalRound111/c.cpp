#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e5) + 10;
int bit1[N], bit2[N], bit3[N], bit4[N];
const int inf = N;
ll a[N];

int LSOne(int x){
    return x & (-x);
}

void update(int x, int val, int bit[]){
    while(x < N){
        bit[x] = min(bit[x], val);
        x += LSOne(x);
    }
}

int query(int x, int bit[]){
    int mn = inf;

    while(x > 0){
        mn = min(mn, bit[x]);
        x -= LSOne(x);
    }

    return mn;
}

int con[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
    
        vector< int > v;

        for(int i = 1 ; i <= n ; i++){
            scanf("%lld", &a[i]);
            v.push_back(a[i]);
        }

        sort(v.begin(), v.end());

        for(int i = 1 ; i <= n ; i++){
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
            bit1[i] = bit2[i] = bit3[i] = bit4[i] = inf;
        }

        bit1[n + 1] = bit2[n + 1] = bit3[n + 1] = bit4[n + 1] = inf;

        for(int i = n ; i >= 1 ; i--){
            int q = query(a[i], bit2);

            con[i] = q;

            // printf("%d has %d\n", i, con[i]);

            q = query(a[i], bit1);

            update(a[i], q, bit2);
            update(a[i], i, bit1);
        }

        for(int i = n ; i >= 1 ; i--){
            int q = query(n + 1 - a[i], bit4);

            con[i] = min(con[i], q);

            // printf("%d has %d\n", i, con[i]);

            q = query(n + 1 - a[i], bit3);

            update(n + 1 - a[i], q, bit4);
            update(n + 1 - a[i], i, bit3);
        }

        multiset< int > mst;

        mst.insert(inf);

        int i = 1;
        int j = 1;

        ll ans = 0LL;

        while(i <= n){
            while(j <= n && *mst.begin() > j){
                mst.insert(con[j]);
                j++;
            }

            ans += (j - i);

            auto u = mst.find(con[i]);
            mst.erase(u);
            i++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}