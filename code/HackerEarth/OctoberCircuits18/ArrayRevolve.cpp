//31, 10, 2018, 13:26:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N];

class Node{
    public:
        ll sum;
        ll lazy;
};

class Segtree{
    private:
        Node nodes[N << 4];
    public:
        void shift(int node){
            int lf = node << 1;
            int rg = lf + 1;

            nodes[lf].lazy += nodes[node].lazy;
            nodes[rg].lazy += nodes[node].lazy;
            nodes[node].sum += nodes[node].lazy;
            nodes[node].lazy = 0LL; 
        }

        void build(int node, int l, int r){
            if(l == r){
                nodes[node].sum = a[l];
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (l + r) / 2;

                build(lf, l, mid);
                build(rg, mid + 1, r);

                nodes[node].sum = nodes[lf].sum + nodes[rg].sum;
            }
        }

        void update(int node, int i, int j, int l, int r, ll val){
            if(nodes[node].lazy){
                shift(node);
            }

            if(i > r || j < l){
                return;
            }

            if(l <= i && j <= r){
                nodes[node].lazy += val;

                shift(node);
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                update(lf, i, mid, l, r, val);
                update(rg, mid + 1, j, l, r, val);

                nodes[node].sum = nodes[lf].sum + nodes[rg].sum;
            }
        }

        ll query(int node, int i, int j, int l, int r){
            if(nodes[node].lazy){
                shift(node);
            }

            if(i > r || j < l){
                return 0LL;
            }

            if(l <= i && j <= r){
                return nodes[node].sum;
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                return query(lf, i, mid, l, r) + query(rg, mid + 1, j, l, r);
            }
        }

};

Segtree *segtree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    segtree = new Segtree();

    int n, q;

    scanf("%d %d", &n, &q);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }

    segtree->build(1, 1, n);

    while(q--){
        int op;

        scanf("%d", &op);

        if(op == 1){
            int id;
            int val;

            scanf("%d %d", &id, &val);

            int qu = n / val;

            segtree->update(1, 1, n, 1, n, ll(qu));

            int r = n % val;
            int tend = n - id + 1;

            if(tend >= r){
                segtree->update(1, 1, n, id, id + r - 1, 1);
            }else{
                segtree->update(1, 1, n, id, n, 1);
                r -= tend;

                segtree->update(1, 1, n, 1, r, 1);
            }
        }else{
            int l, r;

            scanf("%d %d", &l, &r);

            if(l > r){
                printf("%lld\n", segtree->query(1, 1, n, l, n) +
                    segtree->query(1, 1, n, 1, r)
                );
            }else{
                printf("%lld\n", segtree->query(1, 1, n, l, r));
            }
        }
    }

    return 0;
}