#include <bits/stdc++.h>

using namespace std;

const int N = int(5e5) + 10;
const int K = 20;
int ans[N];
int p[N];
int cicle_num[N];
int cicle_pos[N];
vector< int > adj[N];
vector< vector< int > > cicles;
vector< vector< int > > cntcicles;
int father[N][K];
bool in_cicle[N];
int vis[N];
int fk[N];

int dfs1(int u){
    vis[u] = 1;
    int r = 0;

    if(vis[p[u]] == 1){
        // printf("heyy: %lu\n", cicles.size());
        cicles.push_back({u});

        cicle_num[u] = cicles.size();
        cicle_pos[u] = cicles[cicle_num[u] - 1].size();

        r = p[u];
    }else if(vis[p[u]] == 0){
        int d = dfs1(p[u]);

        if(d){
            cicles[int(cicles.size()) - 1].push_back(u);

            if(d != u){
                r = d;
            }

            cicle_num[u] = cicles.size();
            cicle_pos[u] = cicles[cicle_num[u] - 1].size();
        }
    }

    vis[u] = 2;

    return r;
}

void dfs2(int u){
    ans[u] = 1;

    for(auto v: adj[u]){
        if(!cicle_num[v]){
            dfs2(v);
            ans[u] += ans[v] - fk[v];        
        }
    }
}

int get_father(int i, int k){
    int cur = i;

    for(int d = K - 1 ; d >= 0 ; d--){
        if(k & (1 << d)){
            cur = father[cur][d];
            k -= (1 << d);
        }
    }

    return cur;
}

pair< int, int > get_fartest(int i){
    int dist = 0;
    int cur = i;

    for(int d = K - 1 ; d >= 0 ; d--){
        if(father[cur][d]){
            dist += (1 << d);
            cur = father[cur][d];
        }
    }

    return make_pair(cur, dist);
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &p[i]);

        adj[p[i]].push_back(i);
    }

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            // printf("run on %d\n", i);
            dfs1(i);
        }
    }

    // printf("having %lu\n", cicles.size());

    for(int i = 1 ; i <= n ; i++){
        if(cicle_num[i]){
            father[i][0] = 0;
        }else{
            father[i][0] = p[i];
        }
    }

    for(int k = 1 ; k < K ; k++){
        for(int i = 1 ; i <= n ; i++){
            father[i][k] = father[father[i][k - 1]][k - 1];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int kfather = get_father(i, k);

        fk[kfather]++;
    }

    for(auto &u: cicles){
        reverse(u.begin(), u.end());
    }

    for(int i = 1 ; i <= n ; i++){
        if(cicle_num[i]){
            cicle_pos[i] = cicles[cicle_num[i] - 1].size() - cicle_pos[i];
        }
    }

    for(auto &u: cicles){
        int sz = u.size();
        // printf("sz = %d\n", sz);

        // printf("cicle: ");
        // for(auto e: u){
        //     printf("%d ", e);
        // }
        // printf("\n");

        for(int i = 0 ; i < sz ; i++){
            u.push_back(u[i]);
        }

        cntcicles.push_back(vector< int >(u.size() + 2, 0));
    }

    for(int i = 1 ; i <= n ; i++){
        if(cicle_num[i]){
            dfs2(i);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        auto u = get_fartest(i);

        if(u.second < k){
            
            int rest = k - u.second;

            rest = min(rest, int(cicles[cicle_num[u.first] - 1].size() / 2 - 1));

            // printf("%d arrives on %d with %d resting %d | %d\n", i, u.first, u.second, rest, cicle_num[u.first]);

            cntcicles[cicle_num[u.first] - 1][cicle_pos[u.first] + 1]++;
            cntcicles[cicle_num[u.first] - 1][cicle_pos[u.first] + rest + 1]--;
        }
    }

    // for(int i = 1 ; i <= n ; i++){
    //     printf("%d, ", ans[i]);
    // }
    // printf("\n");

    for(int j = 0 ; j < cicles.size() ; j++){
        int cur = 0;

        for(int i = 0 ; i < cicles[j].size() ; i++){
            cur += cntcicles[j][i];
            // printf("inc %d [%d], tot %d\n", cntcicles[j][i], cicles[j][i], cur);

            ans[cicles[j][i]] += cur;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}