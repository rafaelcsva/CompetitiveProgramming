#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(3e5) + 10;
int pref[N];
ll h[N];
ll dp[N];
ll b[N];
ll segtree[N << 4];
const ll inf = ll(1e18);

void update(int node, int i, int j, int pos, ll val){
    if(j < pos || i > pos){
        return;
    }

    if(i == pos && j == pos){
        segtree[node] = val;
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        update(lf, i, mid, pos, val);
        update(rg, mid + 1, j, pos, val);

        segtree[node] = max(segtree[lf], segtree[rg]);
    }
}

ll query(int node, int i, int j, int l, int r){
    if(l > r){
        return -inf;
    }

    if(j < l || i > r){
        return -inf;
    }

    if(l <= i && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        return max(query(lf, i, mid, l, r), query(rg, mid + 1, j, l, r));
    }
}

int main(){
    for(int i = 0 ; i < (N << 4) ; i++){
        segtree[i] = -inf;
    }

    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &h[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &b[i]);
    }

    stack< int > stc;

    for(int i = 1 ; i <= n ; i++){
        while(!stc.empty() && h[stc.top()] > h[i]){
            stc.pop();
        }

        if(!stc.empty()){
            pref[i] = stc.top();
        }

        stc.push(i);
    }

    // printf("squi!\n");
    dp[1] = b[1];

    update(1, 1, N, 1, dp[1]);

    for(int i = 2 ; i <= n ; i++){
        ll q = query(1, 1, N, max(pref[i], 1), i - 1);
        if(pref[i] == 0){
            q = max(q, 0LL);

            dp[i] = q + b[i];
        }else{
            dp[i] = max(q + b[i], query(1, 1, N, pref[i], pref[i]));
        }

        update(1, 1, N, i, dp[i]);
    }

    printf("%lld\n", dp[n]);

    return 0;
}