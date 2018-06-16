//30, 05, 2018, 16:42:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 100);
int sta[N], en[N];
int par[N];
int v[N];
int vt[N];
int pt = 1;
const ll ERROR = -1e9;
vector< vector<int> > adj;

void dfs(int u, int f, int deep){
    vt[pt] = u;
    sta[u] = pt;
    par[u] = deep;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(v == f)
            continue;

        pt++;
        dfs(v, u, !deep);
    }

    en[u] = pt;
}

class Node{
    public:
        int value;
        int lazy0 = 0;
        int lazy1 = 0;

        Node(int v){
            value = v;
        }

        Node(){
            
        }
};

class SegTree{
    public:
        Node nodes[N << 4];

        void build(int node, int i, int j){
            if(i == j){
                nodes[node] = Node(v[vt[i]]);
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                build(left, i, mid), build(right, mid + 1, j);
            }
        }

        void shift(int node, int i, int j){
            if(i == j){
                if(par[vt[i]] == 0){
                    nodes[node].value += nodes[node].lazy0;
                    nodes[node].value -= nodes[node].lazy1;
                }else{
                    nodes[node].value += nodes[node].lazy1;
                    nodes[node].value -= nodes[node].lazy0;
                }

                nodes[node].lazy0 = nodes[node].lazy1 = 0;
            }else{
                int left = node << 1;
                int right = left + 1;

                nodes[left].lazy0 += nodes[node].lazy0, nodes[left].lazy1 += nodes[node].lazy1;
                nodes[right].lazy0 += nodes[node].lazy0, nodes[right].lazy1 += nodes[node].lazy1;

                nodes[node].lazy0 = nodes[node].lazy1 = 0;
            }
        }

        void update(int node, int i, int j, int l, int r, int deep, int v){
            if(nodes[node].lazy1 || nodes[node].lazy0){
                shift(node, i, j);
            }

            if(i > r || j < l){
                return;
            }

            if(i >= l && j <= r){
                if(deep){
                    nodes[node].lazy1 += v;
                }else{
                    nodes[node].lazy0 += v;
                }
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                update(left, i, mid, l, r, deep, v);
                update(right, mid + 1, j, l, r, deep, v);
            }
        }

        Node query(int node, int i, int j, int v){
            if(nodes[node].lazy0 || nodes[node].lazy1){
                shift(node, i, j);
            }

            if(i > v || j < v){
                return Node(ERROR);
            }

            if(i == v && j == v){
                
                return nodes[node];
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                Node lf = query(left, i, mid, v);
                Node rg = query(right, mid + 1, j, v);

                if(lf.value == ERROR){
                    return rg;
                }

                return lf;
            }
        }
};

SegTree segtree;

int main(){
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    adj.resize(n + 2);

    for(int i = 1 ; i <= n ; i++){
        cin >> v[i];
    }

    for(int i = 0 ; i < n - 1 ; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v), adj[v].push_back(u);
    }

    dfs(1, 1, 0);
    
    segtree.build(1, 1, n);
    
    for(int i = 1 ; i <= m ; i++){
        int t, x;

        cin >> t;
        cin >> x;

        if(t == 1){
            int val;

            cin >> val;

            int l = sta[x], r = en[x];
            
            segtree.update(1, 1, n, l, r, par[x], val);
        }else{
            int pos = sta[x];
            
            cout << segtree.query(1, 1, n, pos).value << endl;
        }
    }

    return 0;
}