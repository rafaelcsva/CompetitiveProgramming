//30, 10, 2018, 19:23:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
const int inf = -1e9;
ll a[N];

class Node{
    public:
        ll suml = inf, sumr = inf, sum = inf, best = inf;

        void fill(ll &x){
            this->suml = this->sumr = this->sum = this->best = x;
        }
};

class Segtree{
    Node nodes[N << 4];

    public:
        Node merge(Node &a, Node &b){
            Node r;

            r.sum = a.sum + b.sum;
            
            r.suml = max(a.suml, a.sum + b.suml);
            r.sumr = max(b.sumr, b.sum + a.sumr);
            r.best = max({r.sum, r.suml, r.sumr, a.sumr + b.suml, a.best, b.best});

            return r;
        }

        void build(int node, int l, int r){
            if(l == r){
                nodes[node].fill(a[l]);
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (l + r) / 2;

                build(lf, l, mid);
                build(rg, mid + 1, r);

                nodes[node] = merge(nodes[lf], nodes[rg]);
            }
        }

        Node query(int node, int i, int j, int l, int r){
            if(j < l || i > r){
                Node err;

                return err; 
            }

            if(l <= i && j <= r){
                return nodes[node];
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                Node lef = query(lf, i, mid, l, r);
                Node rig = query(rg, mid + 1, j, l, r);

                if(lef.sum == inf){
                    return rig;
                }

                if(rig.sum == inf){
                    return lef;
                }

                return merge(lef, rig);
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
        int l, r;

        scanf("%d %d", &l, &r);

        Node md = segtree->query(1, 1, n, l, r);
        Node lf = segtree->query(1, 1, n, 1, l - 1);
        Node rg = segtree->query(1, 1, n, r + 1, n);

        printf("%lld\n", max({md.best, lf.best, rg.best, md.sumr + lf.sumr,
                    md.suml + rg.suml, lf.sumr + md.sum + rg.suml}));
    }
    
    return 0;
}