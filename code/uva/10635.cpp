//06, 08, 2018, 15:46:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 10);
int idx[N];
int a[N];
int dp[N];

class SegTree{
    public:
        int nodes[N << 4];

        void clear(){
            memset(nodes, 0, sizeof nodes);
        }

        void update(int node, int i, int j, int pos, int value){
            if(i > pos || j < pos){
                return;
            }

            if(i == pos && j == pos){
                nodes[node] = value;
            }else{
                int mid = (i + j) / 2;
                int lf = node << 1;
                int rg = lf + 1;

                update(lf, i, mid, pos, value);
                update(rg, mid + 1, j, pos, value);

                nodes[node] = max(nodes[lf], nodes[rg]);
            }
        }

        int query(int node, int i, int j, int l, int r){
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n, p, q;

        scanf("%d %d %d", &n, &p, &q);

        for(int i = 0 ; i <= p ; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1 ; i <= q + 1 ; i++){
            int x;

            scanf("%d", &x);

            idx[x] = i;
        }

        for(int i = p ; i >= 0 ; i--){
            dp[i] = 1;

            if(idx[a[i]]){
                dp[i] += segtree.query(1, 1, q + 1, idx[a[i]], q + 1);
                segtree.update(1, 1, q + 1, idx[a[i]], dp[i]);
            }
        }

        printf("Case %d: %d\n", test, dp[0]);
        
        segtree.clear();
        memset(idx, 0, sizeof idx);
    }

    return 0;
}