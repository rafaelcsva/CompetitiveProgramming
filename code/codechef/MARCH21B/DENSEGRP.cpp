#include <bits/stdc++.h>

using namespace std;

typedef vector< int >   vi;

const int N = int(8e5) + 10;
const int inf = int(1e9) + 10;
int a[N], b[N], c[N], d[N];
pair< vi, vi > segtree[N << 2];
bool taked[N];
int dis[N];

void update(int node, int i, int j, int l, int r, int id, bool erase){
    if(j < l || i > r){
        return;
    }

    if(l <= i && j <= r){
        if(!erase){
            segtree[node].first.push_back(id);
        }else{
            segtree[node].first.clear();
        }
    }else{
        if(!erase){
            segtree[node].second.push_back(id);
        }else{
            segtree[node].second.clear();
        }
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        update(lf, i, mid, l, r, id, erase);
        update(rg, mid + 1, j, l, r, id, erase);
    }
}

void query(int node, int i, int j, int l, int r, vector< int > &ans) {
    if(j < l || i > r || (segtree[node].first.size() + segtree[node].second.size() == 0)){
        return;
    }

    if(l <= i && j <= r){
        for(auto u: segtree[node].first){
            if(!taked[u]){
                taked[u] = true;
                ans.push_back(u);
            }
        }

        for(auto u: segtree[node].second){
            if(!taked[u]){
                ans.push_back(u);
                taked[u] = true;
            }
        }

        segtree[node].first.clear();
        segtree[node].second.clear();
    }else{
        for(auto u: segtree[node].first){
            if(!taked[u]){
                taked[u] = true;
                ans.push_back(u);
            }
        }

        segtree[node].first.clear();

        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        query(lf, i, mid, l, r, ans);
        query(rg, mid + 1, j, l, r, ans);
    }
}

void bfs(int x){
    queue< int > q;
    q.push(x);

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        vector< int > adj;
        query(1, 1, N, c[u], d[u], adj);

        for(auto v: adj){
            // printf("v: %d\n", v);
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                // printf("push %d from %d\n", v, u);
                q.push(v);
            }
        }
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m, x, y;

        vector< int > idx;

        scanf("%d %d %d %d", &n, &m, &x, &y);

        idx.push_back(x);
        idx.push_back(y);

        for(int i = 1 ; i <= m ; i++){
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

            idx.push_back(a[i]);
            idx.push_back(b[i]);
            idx.push_back(c[i]);
            idx.push_back(d[i]);
        }

        sort(idx.begin(), idx.end());
        idx.erase(unique(idx.begin(), idx.end()), idx.end());
    
        for(int i = 1 ; i <= m ; i++){
            a[i] = lower_bound(idx.begin(), idx.end(), a[i]) - idx.begin() + 1;
            b[i] = lower_bound(idx.begin(), idx.end(), b[i]) - idx.begin() + 1;
            c[i] = lower_bound(idx.begin(), idx.end(), c[i]) - idx.begin() + 1;
            d[i] = lower_bound(idx.begin(), idx.end(), d[i]) - idx.begin() + 1;
        }

        x = lower_bound(idx.begin(), idx.end(), x) - idx.begin() + 1;
        y = lower_bound(idx.begin(), idx.end(), y) - idx.begin() + 1;

        for(int i = 1 ; i <= m ; i++){
            dis[i] = -1;
        }

        dis[0] = 0;
        c[0] = d[0] = x;

        for(int i = 1 ; i <= m ; i++){
            // printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
            update(1, 1, N, a[i], b[i], i, false);
        }

        bfs(0);

        int ans = inf;
        for(int i = 0 ; i <= m ; i++){
            if(c[i] <= y && y <= d[i] && dis[i] != -1){
                // printf("%d %d %d\n", c[i], d[i], dis[i]);
                ans = min(ans, dis[i]);
            }
        }

        printf("%d\n", ans == inf ? -1 : ans);

        //clear seg

        for(int i = 1 ; i <= m ; i++){
            update(1, 1, N, a[i], b[i], i, true);
        }

        for(int i = 0 ; i <= 2 * m ; i++){
            taked[i] = false;
        }
    }

    return 0;
}
