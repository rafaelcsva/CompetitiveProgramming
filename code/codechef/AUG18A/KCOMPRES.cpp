//06, 08, 2018, 11:35:27 Rafaelcs cpp
#include <bits/stdc++.h>
    
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
    
typedef unsigned long long ull;
    
const int N = int(1e5 + 10);
int a[N], ra[N];
map<int, int> mp;
set<int>st;
vector< pii > vt, vtr;
vector< vector< int > > idx, idxr;
int n, s;
    
class SegTree{
    public:
        int nodes[N << 3];
    
        void clear(){
            memset(nodes, 0, sizeof nodes);
        }
    
        void build(int node, int i, int j){
            if(i == j){
                nodes[node] = a[i];
            }else{
                int mid = (i + j) / 2;
                int lf = node << 1;
                int rg = lf + 1;
    
                build(lf, i, mid);
                build(rg, mid + 1, j);
    
                nodes[node] = max(nodes[lf], nodes[rg]);
            }
        }
    
        void update(int node, int i, int j, int p, int v){
            if(i > p || j < p){
                return;
            }
    
            if(i == p && j == p){
                nodes[node] = v;
            }else{
                int mid = (i + j) / 2;
                int lf = node << 1;
                int rg = lf + 1;
    
                update(lf, i, mid, p, v);
                update(rg, mid + 1, j, p, v);
    
                nodes[node] = max(nodes[lf], nodes[rg]);
            }
        }
    
        int query(int node, int i, int j, int l, int r){
            if(l > r){
                return -1;
            }
            
            if(i > r || j < l){
                return -1;
            }
    
            if(i >= l && j <= r){
                return nodes[node];
            }else{
                int mid = (i + j) / 2;
                int lf = node << 1;
                int rg = lf + 1;
    
                return max(query(lf, i, mid, l, r), query(rg, mid + 1, j, l, r));
            }
        }
};
    
SegTree segtree;
int b[N];
    
bool can(int k, int *a, vector< pii > &vt, vector< vector< int > > &idx){
    if(k == 0){
        return n <= s;
    }

    segtree.clear();
    memset(b, 0, sizeof b);
    
    // printf("tentando para k = %d\n", k);
    for(int i = 0 ; i < vt.size() ; i++){
        pii u = vt[i];
        int pos = u.second;
        // printf("comecei %d\n", b[pos]);
        
        if(b[pos])
            continue;

        // printf("aqui\n");
        // printf("%d (%d) ", u.first, u.second);
        int l = max(1, pos - k);
        int r = min(n, pos + k);
    
        int lf = segtree.query(1, 1, n, l, pos - 1);
        int rg = segtree.query(1, 1, n, pos + 1, r);
    
        rg = max(rg, lf);
        
        // printf("%d %d\n", pos, b[pos]);
        int j = lower_bound(idx[u.first].begin(), idx[u.first].end(), pos) - idx[u.first].begin();
        int last = pos;
        int resp = rg + 1;
        
        for(int t = j + 1 ; t < idx[u.first].size() ; t++){
            int f = idx[u.first][t];

            if(f - last > k){
                break;
            }

            int l = max(1, f - k);
            int r = min(n, f + k);
    
            int rg = segtree.query(1, 1, n, pos + 1, r);
    
            resp = max(resp, rg + 1);

            last = f;
        }

        last = pos;

        for(int t = j - 1 ; t >= 0 ; t--){
            int f = idx[u.first][t];

            if(last - f > k){
                break;
            }

            int l = max(1, f - k);
            int r = min(n, f + k);
        
            int lf = segtree.query(1, 1, n, l, pos - 1);

            resp = max(resp, lf + 1);
            
            last = f;
        }

        for(int t = j + 1 ; t < idx[u.first].size() ; t++){
            int f = idx[u.first][t];

            if(f - last > k){
                break;
            }

            b[f] = resp;

            segtree.update(1, 1, n, f, b[f]);

            last = f;
        }

        last = pos;

        for(int t = j - 1 ; t >= 0 ; t--){
            int f = idx[u.first][t];

            if(last - f > k){
                break;
            }

            b[f] = resp;

            segtree.update(1, 1, n, f, b[f]);
            
            last = f;
        }

        b[pos] = resp;
        segtree.update(1, 1, n, pos, b[pos]);
    }
    // printf("  ---  finalized\n");
    int sum = 0;
    
    // printf("testing for k = %d\n", k);
    
    for(int i = 1 ; i <= n ; i++){
        sum += b[i];
        // printf("%d ", b[i]);
        if(sum > s){
            // printf("overflow!\n");
            return false;
        }
    
    }
    // printf("\n");
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    
    scanf("%d", &t);
    
    for(int test = 1 ; test <= t ; test++){
        scanf("%d %d", &n, &s);

        idx.resize(n + 1);
        idxr.resize(n + 1);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
    
            st.insert(a[i]);
        }

        int vl = 1;
    
        for(int u: st){
            // printf("--- %d\n", u);
            mp[u] = vl;
            vl++;
        }
    
        for(int i = 1 ; i <= n ; i++){
            a[i] = mp[a[i]];
            vt.push_back({a[i], i});
            idx[a[i]].push_back(i);
        }

        sort(vt.begin(), vt.end());

        int bg = 0, en = n;
        int r = -1;
    
        while(bg <= en){
            int mid = (bg + en) / 2;
    
            if(can(mid, a, vt, idx)){
                bg = mid + 1;
                r = mid;
            }else{
                en = mid - 1;
            }
        }
    
        printf("%d\n", r + 1);
        
        st.clear();
        vt.clear();
        idx.clear();
    }
    
    return 0;
} 