#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = int(2e5 + 10);
ordered_set< int > s[N << 3];
int a[N], b[N];
int pos[N], pos2[N];

void update(int node, int l, int r, int pos, int valr, int valadd){
    if(l > pos || r < pos){
        return;
    }

    // printf("node: %d\n", node);
    // printf("%d, %d\n", l, r);

    s[node].erase(valr);

    if(valadd != -1)
        s[node].insert(valadd);

    if(l == pos && r == pos){
        return;
    }else{
        int mid = (l + r) >> 1;
        int lf = node << 1;
        int rg = lf + 1;
        update(lf, l, mid, pos, valr, valadd);
        update(rg, mid + 1, r, pos, valr, valadd);
    }
}

int query(int node, int i, int j, int la, int ra, int lb, int rb){
    if(i > ra || j < la){
        return 0;
    }

    if(i >= la && j <= ra){
        // printf("q: %d %d %lu %d\n", i, j, s[node].size(), *s[node].begin());
        return s[node].order_of_key(rb + 1) - s[node].order_of_key(lb);
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        return query(lf, i, mid, la, ra, lb, rb) + query(rg, mid + 1, j, la, ra, lb, rb);
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        pos2[a[i]] = i;
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &b[i]);
        pos[b[i]] = i;
    }

    for(int i = 1 ; i <= n ; i++){
        update(1, 1, n, i, -1, pos[a[i]]);
    }

    while(m--){
        int t;

        scanf("%d", &t);

        if(t == 1){
            int la, ra, lb, rb;

            scanf("%d %d %d %d", &la, &ra, &lb, &rb);

            printf("%d\n", query(1, 1, n, la, ra, lb, rb));
        }else{
            int x, y;
            
            scanf("%d %d", &x, &y);

            swap(pos[b[x]], pos[b[y]]);
            swap(b[x], b[y]);

            // printf("%d %d %d\n", pos2[b[y]], pos[b[x]], pos[b[y]]);

            update(1, 1, n, pos2[b[y]], pos[b[x]], -1);
            update(1, 1, n, pos2[b[x]], pos[b[y]], -1);
            update(1, 1, n, pos2[b[y]], -1, pos[b[y]]);
            update(1, 1, n, pos2[b[x]], -1, pos[b[x]]);

        }
    }

    return 0;
}