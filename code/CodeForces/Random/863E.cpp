//14, 08, 2018, 16:49:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

map<int, int>idx;
const int N = 8e5 + 10;
pii querys[N];
set< int > st;

class Node{
    public:
        int value, lazy;

        Node(){
            value = lazy = 0;
        }
};

class SegTree{
    public:
        Node nodes[N << 3];

        void shift(int node){
            nodes[node].value += nodes[node].lazy;

            int lf = node << 1;
            int rg = lf + 1;

            nodes[lf].lazy += nodes[node].lazy;
            nodes[rg].lazy += nodes[node].lazy;

            nodes[node].lazy = 0;
        }

        void update(int node, int i, int j, int l, int r){
            if(nodes[node].lazy){
                shift(node);
            }

            if(i > r || j < l){
                return;
            }

            if(i >= l && j <= r){
                nodes[node].lazy++;
                shift(node);
            }else{
                int mid = (i + j) / 2;
                int lf = node << 1;
                int rg = lf + 1;

                update(lf, i, mid, l, r);
                update(rg, mid + 1, j, l, r);

                nodes[node].value = min(nodes[lf].value, nodes[rg].value);
            }
        }

        int query(int node, int i, int j, int l, int r){
            if(nodes[node].lazy){
                shift(node);
            }

            if(i > r || j < l){
                return -1;
            }

            if(i >= l && j <= r){
                return nodes[node].value;
            }else{
                int mid = (i + j) / 2;
                int lf = node << 1;
                int rg = lf + 1;

                int rl = query(lf, i, mid, l, r);
                int rr = query(rg, mid + 1, j, l, r);

                if(rl == -1){
                    return rr;
                }else if(rr == -1){
                    return rl;
                }

                return min(rr, rl);
            }
        }
};

SegTree segtree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &querys[i].first, &querys[i].second);
        st.insert(querys[i].first);
        st.insert(querys[i].second);
    }

    int e = 0;
    int past = 0;
    
    for(set< int >::iterator it = st.begin() ; it != st.end() ; it++){
        int u = *it;
        
        if(idx[u] == 0){
            idx[u] = ++e;
            if(past != 0){
                if(u != past + 1){
                    idx[u]++;
                    ++e;
                }
            }
            
            past = u;
        }
    }

    for(int i = 0 ; i < n ; i++){
        querys[i].first = idx[querys[i].first];
        querys[i].second = idx[querys[i].second];

        segtree.update(1, 1, e, querys[i].first, querys[i].second);
    }

    for(int i = 0 ; i < n ; i++){
        int v = segtree.query(1, 1, e, querys[i].first, querys[i].second);

        if(v > 1){
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}