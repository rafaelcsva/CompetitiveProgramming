#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair< int, int >    pii;
 
const int N = int(1e6) + 10;
 
pii segtree[N << 3];
int lazy[N<<3];
 
int get(int node, int sz){
    if(segtree[node].first){
        assert(segtree[node].first > 0);
        
        return sz;
    }    
    
    return segtree[node].second;
}
 
void update(int node, int i, int j, int l, int r, int val){
    if(l > r) return;
 
    if(i > r || j < l){
        return;
    }
    
    if(i >= l && j <= r){
        segtree[node].first += val;
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;
        
        update(lf, i, mid, l, r, val);
        update(rg, mid + 1, j, l, r, val);
        
        segtree[node].second = get(lf, mid - i + 1) + get(rg, j - (mid + 1) + 1);
    }
}
 
int query(int node, int i, int j, int l, int r){
    if(i > r || j < l){
        return 0LL;
    }
    
    if(i >= l && j <= r){
        return get(node, j - i + 1LL);   
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;
        
        return query(lf, i, mid, l, r) + query(rg, mid + 1, j, l, r);
    }
}
 
class Seg{
    public:
    int li, ri, wi;
};
 
Seg segs[N];
int n, m;
 
bool compar(Seg a, Seg b){
    return a.wi < b.wi;
}
 
void clear(int l, int r){
    for(int i = l ; i <= r ; i++){
        update(1, 1, m, segs[i].li, segs[i].ri, -1);
    }
}
 
int can(){
    int pt = 0;
    int ans = int(1e9);

    update(1, 1, m, segs[pt].li, segs[pt].ri, 1);
 
    if(query(1, 1, m, 1, m) == m){
        return 0;
    }
 
    for(int i = 1 ; i < n ; i++){
        bool ver = false;

        update(1, 1, m, segs[i].li, segs[i].ri, 1);
    
        if(query(1, 1, m, 1, m) == m){
            ver = true;
        }

        while(query(1, 1, m, 1, m) == m){
            update(1, 1, m, segs[pt].li, segs[pt].ri, -1);
            pt++;
        }

        if(ver){
            // printf("test %d - %d %d %d\n", pt - 1, i);
            ans = min(ans, segs[i].wi - segs[pt - 1].wi);
        }
    }
 
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
 
    for(int i = 0 ; i < n ; i++){
        cin >> segs[i].li >> segs[i].ri >> segs[i].wi;
 
        if(segs[i].li > 1){
            segs[i].li++;
        }
    }
 
    sort(segs, segs + n, compar);
 
    printf("%d\n", can());
 
    return 0;
}