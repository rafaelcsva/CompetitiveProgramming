#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>  pii;
const int N = int(1e5 + 100);
int a[N], b[N];
int segtree[N << 4], segtree2[N << 4], lazy[N << 4];
int n;
map<int, int>mp;
vector<int> ind[N];

void build(int node, int i, int j){
    lazy[node] = 0;

    if(i == j){
        segtree[node] = a[i];
        
        segtree2[node] = b[i];
    }else{
        int mid = (i + j) / 2;
        int left = node << 1;
        int right = left | 1;

        build(left, i, mid);
        build(right, mid + 1, j);

        segtree[node] = min(segtree[left], segtree[right]);
        segtree2[node] = max(segtree2[left], segtree2[right]);
    }
}

void next(int node){
    int left = node << 1;
    int right = left | 1;

    segtree[node] = lazy[node];
    lazy[left] = lazy[node];
    lazy[right] = lazy[node];

    lazy[node] = 0;
}

pii query(int i, int j, int node, int l, int r){
    if(lazy[node]){
        next(node);
    }
    if(i > r || j < l){
        return {-1, -1};
    }

    if(i >= l && j <= r){
        return {segtree[node], segtree2[node]};
    }else{
        int mid = (i + j) / 2;
        int left = node << 1;
        int right = left | 1;

        pii re = query(i, mid, left, l, r);
        pii rd = query(mid + 1, j, right, l, r);
        
        if(re.first == -1){
            return rd;
        }else if(rd.first == -1){
            return re;
        }

        return {min(rd.first, re.first), max(rd.second, re.second)};
    }
}

void update(int i, int j, int node, int l, int r, int w){
    if(lazy[node]){
        next(node);
    }

    if(i > r || j < l){
        return;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (i + j) / 2;

    if(i >= l && j <= r){
        lazy[node] = w;
        next(node);
    }else{
        update(i, mid, left, l, r, w);
        update(mid + 1, j, right, l, r, w);

        segtree[node] = min(segtree[left], segtree[right]);
    }
}

bool can(pii q, int c){
    return q.first >= c && q.second <= c;
}

int main (){
    int t;

    scanf("%d", &t);

    while(t--){
        int ma = -1;
        int id = 0;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        bool ok = true;

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &b[i]);

            int u;

            if(mp[b[i]] == 0){
                mp[b[i]] = ++id;
            }

            u = mp[b[i]];

            ind[u].push_back(i);
            
            if(b[i] > a[i])
                ok = false;
        }

        if(ok){
            build(1, 1, n);

            int cut = 0;

            for(int i = 1 ; i <= n ; i++){
                pii q = query(1, n, 1, i, i);
                
                if(q.first != b[i]){
                    int l = i;
                    int u = mp[b[i]];
                    int st = lower_bound(ind[u].begin(), ind[u].end(), i) - ind[u].begin();
                    
                    for(int j = st ; j < ind[u].size() ; j++){
                        int v = ind[u][j];
                        if(can(query(1, n, 1, i, v), b[i])){
                            l = v;
                        }else{
                            break;
                        }
                    }
                    
                    cut++;
                    update(1, n, 1, i, l, b[i]);
                }
            }

            printf("%d\n", cut);
        }else{
            printf("-1\n");
        }

        mp.clear();
        for(int i = 0 ; i <= id ; i++){
            ind[i].clear();
        }
    }

    return 0;
}