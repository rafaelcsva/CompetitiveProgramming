#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = int(2e5) + 10;

vector< pii > cols[N], rows[N];
int a[N], r[N], c[N];
vector< int > adj[N];
int ans[N];
map< pii, int > ver, ver1;

int dfs(int u){
    if(ans[u] != 0){
        return ans[u];
    }

    ans[u] = 1;

    if(ver[{c[u], a[u]}]){
        // printf("aq %d\n", u);
        ans[u] = max(ans[u], ver[{c[u], a[u]}]);
    }else{
        auto v = upper_bound(cols[c[u]].begin(), cols[c[u]].end(), make_pair(a[u], N));

        if(v != cols[c[u]].end()){
            int d = v->first;

            while(v->first == d){
                ans[u] = max(ans[u], 1 + dfs(v->second));
                v++;
            }
        }
    
        ver[{c[u], a[u]}] = ans[u];
    }

    if(ver1[{r[u], a[u]}]){
        ans[u] = max(ans[u], ver1[{r[u], a[u]}]);
    }else{
        auto e = upper_bound(rows[r[u]].begin(), rows[r[u]].end(), make_pair(a[u], N));
        int tmp = 1;

        if(e != rows[r[u]].end()){
            int v = e->first;

            while(e->first == v){
                ans[u] = max(ans[u], 1 + dfs(e->second));
                tmp = max(tmp, 1 + dfs(e->second));
                e++;
            }
        }

        ver1[{r[u], a[u]}] = tmp;
    }

    return ans[u];
}

int main(){
    int h, w, n;

    scanf("%d %d %d", &h, &w, &n);

    for(int i = 0 ; i < n ; i++){
        int ri, ci;

        scanf("%d %d %d", &ri, &ci, &a[i]);

        r[i] = ri;
        c[i] = ci;

        rows[ri].push_back({a[i], i});
        cols[ci].push_back({a[i], i});
    }

    for(int i = 1 ; i <= w ; i++){
        sort(cols[i].begin(), cols[i].end());
    }

    for(int i = 1 ; i <= h ; i++){
        sort(rows[i].begin(), rows[i].end());
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d\n", dfs(i) - 1);
    }

    return 0;
}