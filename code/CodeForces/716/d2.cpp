#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair< int, int >    pii;
 
const int N = int(3e5) + 10;
vector< pii > segtree[N << 2];
int aux[N];
int a[N];
const int C = 2;

vector< pii > merge(vector< pii > a, vector< pii > b){
    if(a.size() == 0){
        return b;
    }

    if(b.size() == 0){
        return a;
    }

    for(auto u: a){
        aux[u.second] += u.first;
    }
 
    for(auto u: b){
        aux[u.second] += u.first;
    }
 
    vector< pii > ans;
 
    for(auto u: a){
        ans.push_back({aux[u.second], u.second});    
    }
 
    for(auto u: b){
        ans.push_back({aux[u.second], u.second});
    }
 
    sort(ans.begin(), ans.end());
 
    auto it = unique(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), it));
 
    reverse(ans.begin(), ans.end());
 
    if(ans.size() > C){
        ans.resize(C);
    }
 
    for(auto u: a){
        aux[u.second] = 0;
    }
 
    for(auto u: b){
        aux[u.second] = 0;
    }
    
    return ans;
}
 
void build(int node, int i, int j){
    // printf("%d %d %d\n", node, i, j);
    if(i == j){
        segtree[node].push_back({1, a[i]});
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;
 
        build(lf, i, mid);
        build(rg, mid + 1, j);
 
        segtree[node] = merge(segtree[lf], segtree[rg]);
    }
}
 
vector< pii > query(int node, int i, int j, int l, int r){
    if(j < l || i > r){
        return {};
    }
 
    // printf("%d %d\n", i, j);
 
    if(l <= i && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;
 
        return merge(query(lf, i, mid, l, r), query(rg, mid + 1, j, l, r));
    }
}
 
vector< int > ind[N];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
 
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);

        ind[a[i]].push_back(i);
    }
 
    build(1, 1, N);
 
    for (int k = 0; k < q; ++k){
        int l, r;
 
        scanf("%d %d", &l, &r);
 
        auto u = query(1, 1, N, l, r);
 
        int val = 0;

        for(auto v: u){
            val = max(val,(int) distance( lower_bound(ind[v.second].begin(), ind[v.second].end(), l), 
            upper_bound(ind[v.second].begin(), ind[v.second].end(), r)));
        }
 
        int x = r - l + 1;
 
        int half = (x + 1) / 2;
        int cnt = 1;
 
        if(half < val){
            int rest = x - val;
 
            val -= (rest + 1);
 
            cnt += val;
        }
 
        printf("%d\n", cnt);
    }
 
	return 0;
}