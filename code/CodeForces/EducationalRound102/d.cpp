#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int segtree[N << 3], segtree1[N << 3];
char s[N];
int a[N];

int query_max(int node, int l, int r, int i, int j){
    if(j < l || i > r){
        return -1000000000;
    }

    if(l <= i && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        return max(query_max(lf, l, r, i, mid), query_max(rg, l, r, mid + 1, j));
    }
}

int query_min(int node, int l, int r, int i, int j){
    if(j < l || i > r){
        return 1000000000;
    }

    if(l <= i && j <= r){
        return segtree1[node];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        return min(query_min(lf, l, r, i, mid), query_min(rg, l, r, mid + 1, j));
    }
}

void build(int node, int l, int r){
    if(l == r){
        segtree[node] = segtree1[node] = a[r];
    }else{
        int mid = (l + r) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        build(lf, l, mid);
        build(rg, mid + 1, r);
        segtree1[node] = min(segtree1[lf], segtree1[rg]);
        segtree[node] = max(segtree[lf], segtree[rg]);
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        scanf("\n%s", s);

        for(int i = 0 ; i < n ; i++){
            a[i + 1] = a[i] + (s[i] == '+' ? 1 : -1);
            // printf("%d ", a[i + 1]);
        }

        build(1, 1, N);

        while(m--){
            int l, r;

            scanf("%d %d", &l, &r);

            int mn = 0, mx = 0;
            int ret = a[r] - a[l - 1];

            if(l > 1){
                mn = min(mn, query_min(1, 1, l - 1, 1, N));

                mx = max(mx, query_max(1, 1, l - 1, 1, N));
            }

            if(r < n){
                // printf("%d\n", query_min(1, r + 1, n, 1, N));
                mn = min(mn, query_min(1, r + 1, n, 1, N) - ret);
                mx = max(mx, query_max(1, r + 1, n, 1, N) - ret);
            }

            printf("%d\n", mx - mn + 1);
        }
    }

    return 0;
}
