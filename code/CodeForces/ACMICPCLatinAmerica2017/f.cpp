//31, 08, 2018, 18:40:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5);
typedef struct{
    int f, s;
    ll g;
}Person;

Person p[N];
map<pii, ll>ver;
map<int, int>mpx, mpy;
set<int>stx, sty;
ll segtree[N << 3];

bool compar(Person &a, Person &b){
    if(a.f < b.f){
        return true;
    }

    if(a.f > b.f){
        return false;
    }

    return a.s > b.s;
}

void update(int node, int i, int j, int f, ll value){
    if(i > f || j < f){
        return;
    }

    if(i == j && i == f){
        segtree[node] = max(segtree[node], value);
    }else{
        int mid = (i + j) / 2;
        int lf = node << 1;
        int rg = lf + 1;

        update(lf, i, mid, f, value);
        update(rg, mid + 1, j, f, value);

        segtree[node] = max(segtree[lf], segtree[rg]);
    }
}

ll query(int node, int i, int j, int l, int r){
    if(l > r){
        return 0LL;
    }
    
    if(i > r || j < l){
        return 0LL;
    }

    if(i >= l && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) / 2;
        int lf = node << 1;
        int rg = lf + 1;

        return max(query(lf, i, mid, l, r), query(rg, mid + 1, j, l, r));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d %lld", &p[i].f, &p[i].s, &p[i].g);

        ver[{p[i].f, p[i].s}] += p[i].g;
        stx.insert(p[i].f);
        sty.insert(p[i].s);
    }

    n = 0;

    for(map<pii, ll>::iterator it = ver.begin() ; it != ver.end() ; it++){
        p[n].f = (it->first).first;
        p[n].s = (it->first).second;
        p[n].g = it->second;
        n++;
    }

    int id = 1;

    for(set<int>::iterator it = stx.begin() ; it != stx.end() ; it++){
        mpx[*it] = id++;
    }

    id = 1;

    for(set<int>::iterator it = sty.begin() ; it != sty.end() ; it++){
        mpy[*it] = id++;
    }

    for(int i = 0 ; i < n ; i++){
        p[i].f = mpx[p[i].f];
        p[i].s = mpy[p[i].s];
    }

    sort(p, p + n, compar);
    
    ll best = 0LL;

    ll carry = 0LL;

    for(int i = 0 ; i < n ; i++){
        ll tmp = 0LL;
        // printf("%d %d\n", p[i].f, p[i].s);
        
        tmp = p[i].g + query(1, 1, N - 1, 1, p[i].s - 1);

        update(1, 1, N - 1, p[i].s, tmp);

        best = max(best, tmp);
    }

    printf("%lld\n", best);
    
    return 0;
}