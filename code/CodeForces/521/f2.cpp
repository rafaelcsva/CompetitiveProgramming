//16, 11, 2018, 13:45:37 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int X = 5001;
const int N = 5001;
ll segtree[N << 1];

void build(ll *arr, int node, int i, int j){
    if(i == j){
        segtree[node] = arr[i];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf | 1;

        build(arr, lf, i, mid);
        build(arr, rg, mid + 1, j);

        segtree[node] = max(segtree[lf], segtree[rg]);
    }
}

ll query(ll *segtree, int node, int i, int j, int l, int r){
    if(l <= i && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) >> 1;

        if(mid >= r){
            return query(segtree, node << 1, i, mid, l, r);
        }else if(mid < l){
            return query(segtree, (node << 1) | 1, mid + 1, j, l, r);
        }else{
            return max(
                query(segtree, node << 1, i, mid, l, r),
                query(segtree, (node << 1) | 1, mid + 1, j, l, r)
            );
        }
    }
}

void update(ll *segtree, int node, int i, int j, int pos, int val){
    if(i > pos || j < pos){
        return;
    }

    if(i == j && i == pos){
        segtree[node] = val;
    }else{
        int mid = (i + j) / 2;
        int lf = node << 1;
        int rg = lf + 1;

        update(segtree, lf, i, mid, pos, val);
        update(segtree, rg, mid + 1, j, pos, val);

        segtree[node] = max(
            segtree[lf],
            segtree[rg]
        );
    }
}

bool ok(int n, int k, int x){
    int last = 0;

    for(int i = 1 ; i <= n ; i++){
        int dis = i - last;

        if(dis == k){
            if(x == 0)
                return false;

            last = i;
            x--;
        }
    }

    return true;
}

ll a[N];
ll dp[N];

int main(){
    int n, k, x;

    scanf("%d %d %d", &n, &k, &x);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }
    
    for(int ex = 1 ; ex <= x ; ex++){
        build(dp, 1, 1, n);

        dp[1] = a[1];

        for(int i = max(ex, 2) ; i <= n ; i++){
            int l = max(1, i - k);

            ll val = query(
                segtree,
                1, 1, n,
                l, i - 1
            );
            
            dp[i] = 0LL;

            if(val == 0LL && (i - (k - 1)) > 1){    
                continue;
            }

            dp[i] = val + a[i];
            // printf("%lld %d %d\n", dp[i], i, ex);
        }
    }

    ll best = 0LL;

    for(int i = n ; i > n - k ; i--){
        best = max(best, dp[i]);
    }

    if(best == 0LL)
        best = -1LL;

    printf("%lld\n", best);
    
    return 0;
}