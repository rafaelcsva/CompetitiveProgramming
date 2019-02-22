//02, 11, 2018, 18:07:12 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
int a[N], r[N], l[N], b[N];
int k;

class Node{
    public:
        int best, lazy;
};

class Segtree{
    public:
        Node nodes[N << 3];

        void shift(int node){
            int lf = node << 1;
            int rg = lf + 1;

            nodes[lf].lazy += nodes[node].lazy;
            nodes[rg].lazy += nodes[node].lazy;
            nodes[node].best += nodes[node].lazy;

            nodes[node].lazy = 0;
        }

        void build(int node, int i, int j){
            if(i == j){
                nodes[node].best = b[i];
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                build(lf, i, mid);
                build(rg, mid + 1, j);


                nodes[node].best = max(nodes[lf].best, nodes[rg].best);
            }
        }

        void update(int node, int i, int j, int l, int r, int val){
            if(l > r){
                return;
            }

            if(nodes[node].lazy){
                shift(node);
            }

            if(i > r || j < l){
                return;
            }

            if(i >= l && j <= r){
                nodes[node].lazy += val;
                shift(node);
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                update(lf, i, mid, l, r, val);
                update(rg, mid + 1, j, l, r, val);

                nodes[node].best = max(nodes[lf].best, nodes[rg].best);
            }
        }

        int query(int node, int i, int j, int l, int r){
            if(nodes[node].lazy){
                shift(node);
            }

            if(i > r || j < l){
                return -1;
            }

            if(l <= i && j <= r){
                return nodes[node].best;
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                int lfr = query(lf, i, mid, l, r);
                int rgr = query(rg, mid + 1, j, l, r);

                return max(lfr, rgr);
            }
        }
};

Segtree *segtree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    segtree = new Segtree();

    int n, q, k;

    scanf("%d %d %d", &n, &q, &k);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }

    int cur = -1;

    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 0){
            cur = -1;
            continue;
        }

        if(cur == -1){
            cur = i;
        }

        l[i] = cur;
    }

    cur = -1;

    for(int i = n ; i >= 1 ; i--){
        if(a[i] == 0){
            cur = -1;
            continue;
        }

        if(cur == -1){
            cur = i;
        }

        r[i] = cur;
    }

    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 1)
            b[i] = r[i] - i + 1;
    }

    segtree->build(1, 1, n);

    int top = n - 1;

    while(q--){
        char c;

        scanf("\n%c", &c);

        int nxt = (top + 1) % n ;

        if(c == '!'){
            if(a[top + 1] == 0){
                top = (top - 1 + n) % n;
                continue;
            }
            
            segtree->update(1, 1, n, l[top + 1], top, -1);
            
            if(l[top + 1] == 1 && (top + 1) != n){
                // cout << top + 1 << " " <<  max(l[n], nxt + 1) << " " << n << endl; 
                segtree->update(1, 1, n, max(l[n], nxt + 1), n, -1);
            }

            if(a[nxt + 1] != 0){
                int q = segtree->query(1, 1, n, nxt + 1, nxt + 1);
                segtree->update(1, 1, n, top + 1, top + 1, q);
                // printf("q = %d %d\n", q, top + 1);
            }

            top = (top - 1 + n) % n;
        }else{
            int q = segtree->query(1, 1, n, 1, n);

            printf("%d\n", min(q, k));
        }
    }

    return 0;
}