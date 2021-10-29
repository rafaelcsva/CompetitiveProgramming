#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int ans[N];
bool is_leaf[N];
vector< int > adj[N];
int a[N];
int dp[N][2];
int father[N];

void balance(multiset< int > &lf, multiset< int > &rg){
    int sz = (lf.size() + rg.size());

    while(rg.size() < (sz + 1) / 2){
        rg.insert(*lf.rbegin());

        auto u = lf.find(*lf.rbegin());
        lf.erase(u);
    } 
    

    while(rg.size() > (sz + 1) / 2){
        lf.insert(*rg.begin());
        rg.erase(rg.begin());
    }
}

int get_ans(multiset< int > &lf, multiset< int > &rg){
    int sz = lf.size() + rg.size();

    if(sz & 1){
        return *rg.begin();
    }else{
        return (*lf.rbegin() + *rg.begin()) / 2;
    }
}

void dfs(int u, int ft, multiset< int > &lf, multiset< int > &rg){
    father[u] = ft;

    if(rg.size() == 0){
        rg.insert(a[u]);
    }else{
        if(*rg.begin() < a[u]){
            rg.insert(a[u]);
        }else{
            lf.insert(a[u]);
        }
    }

    balance(lf, rg);

    bool frag = false;

    for(auto v: adj[u]){
        if(v == ft) continue;

        frag = true;
        dfs(v, u, lf, rg);
    }

    if(!frag){
        is_leaf[u] = true;
        ans[u] = get_ans(lf, rg);
        // printf("calc: %d %d\n", u, ans[u]);
    }

    auto eu = lf.find(a[u]);

    if(eu != lf.end()){
        lf.erase(eu);
    }else{
        rg.erase(rg.find(a[u]));
    }

    balance(lf, rg);
}

int solve(int u, int p){
    int &ansp = dp[u][p];

    if(ansp != -1){
        return ansp;
    }

    if(is_leaf[u]){
        return ans[u];
    }

    if(p){
        ansp = int(1e9) + 10;
    }else{
        ansp = -1;
    }

    for(auto v: adj[u]){
        if(v == father[u]){
            continue;
        }

        if(p){
            ansp = min(ansp, solve(v, !p));
        }else{
            ansp = max(ansp, solve(v, !p));
        }
    }

    return ansp;
}

int main(){
    memset(dp, -1, sizeof dp);
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1 ; i < n ; i++){
        int ui, vi;
        scanf("%d %d", &ui, &vi);

        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    multiset< int > lf, rg;

    dfs(1, 1, lf, rg);

    printf("%d\n", solve(1, 0));

    return 0;
}