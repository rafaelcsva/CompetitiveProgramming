#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;
vector< int > adja[N], adjb[N];
int tin[N], tout[N];
int tim;
int ans;
set< pair< int, int > > con;

void dfsb(int u){
    tin[u] = tim++;

    for(auto v: adjb[u]){
        dfsb(v);
    }

    tout[u] = tim;
}

void dfsa(int u){
    pair< int, int > mtime = {tin[u], tout[u]};

    auto fnd = con.lower_bound(mtime);
    pair< int, int > rmv = {-1, -1};

    if(fnd != con.begin()){
        fnd = prev(fnd);

        if(fnd->first <= mtime.first && fnd->second >= mtime.second){
            rmv = *fnd;
        }
        con.erase(rmv);
    }

    con.insert(mtime);

    ans = max(ans, (int)con.size());
    for(auto v: adja[u]){
        dfsa(v);
    }

    con.erase(mtime);
    if(rmv.first != -1){
        con.insert(rmv);
    }
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 2 ; i <= n ; i++){
            int ai;
            scanf("%d", &ai);

            adja[ai].push_back(i);
        }

        for(int i = 2 ; i <= n ; i++){
            int ai;
            scanf("%d", &ai);

            adjb[ai].push_back(i);
        }

        ans = 0;

        dfsb(1);
        dfsa(1);

        printf("%d\n", ans);

        for(int i = 1 ; i <= n ; i++) adja[i].clear(), adjb[i].clear();
    }

    return 0;
}