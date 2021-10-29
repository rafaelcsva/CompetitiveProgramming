#include <bits/stdc++.h>
 
using namespace std;
 
vector< int > con;
const int N = int(2e5) + 10;
const int M = (N << 3);

string si[N];
int cnt[N * 2];
const int K = 20;
int sparse[N * 2][K];
int llog[2 * N + 1];
int lazzy[M];
int segtree[M];
long long ans[N * 2];
 
vector< int > sort_cyclic_shifts(string const &s){
    int n = s.size();
    const int alphabet = 256;
    vector< int > p(n), c(n), cnt(max(alphabet, n), 0);
 
    for(int i = 0 ; i < n ; i++){
        cnt[s[i]]++;
    }
    for(int i = 1 ; i < alphabet ; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 0 ; i < n ; i++){
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1 ; i < n ; i++){
        if(s[p[i]] != s[p[i - 1]]){
            classes++;
        }
        c[p[i]] = classes - 1;
    }
    vector< int > pn(n), cn(n);
    for(int h = 0 ; (1 << h) < n ; ++h){
        for(int i = 0 ; i < n ; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0){
                pn[i] += n;
            }
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0 ; i < n ; i++){
            cnt[c[pn[i]]]++;
        }
        for(int i = 1 ; i < classes ; i++){
            cnt[i] += cnt[i - 1];
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for(int i = 1 ; i < n ; i++){
            pair< int, int > cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair< int, int > prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if(cur != prev){
                ++classes;
            }
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
 
vector< int > suffix_array_construction(string s){
    s.push_back('$' - 1);
    vector< int > sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
 
    return sorted_shifts;
}
 
vector< int > lcp_construction(string const &s, vector< int > const &p){
    int n = s.size();
    vector< int > rank(n, 0);
    for(int i = 0 ; i < n ; i++){
        rank[p[i]] = i;
    }
    int k = 0;
    vector< int > lcp(n - 1, 0);
    for(int i = 0 ; i < n ; i++){
        if(rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]){
            k++;
        }
        lcp[rank[i]] = k;
        if(k){
            k--;
        }
    }
 
    return lcp;
}
 
void build_sparse_table(int n, vector< int > &a){
    for(int i = 0 ; i < n ; i++){
        sparse[i][0] = a[i];
    }
 
    for(int k = 1 ; k < K ; k++){
        for(int i = 0 ; i + (1 << k) <= n ; i++){
            sparse[i][k] = min(sparse[i][k - 1], sparse[i + (1 << (k - 1))][k - 1]);
        }
    }
}
 
int rmq(int L, int R){
    int j = llog[R - L + 1];
    int minimum = min(sparse[L][j], sparse[R - (1 << j) + 1][j]);
 
    return minimum;
}
 
void push(int node){
    segtree[node] = max(segtree[node], lazzy[node]);
 
    int lf = node << 1;
    int rg = lf + 1;
 
    lazzy[lf] = max(lazzy[lf], lazzy[node]);
    lazzy[rg] = max(lazzy[rg], lazzy[node]);
    lazzy[node] = -1;
}
 
void update(int node, int i, int j, int l, int r, int val){
    if(lazzy[node] != -1){
        push(node);
    }
 
    if(j < l || i > r){
        return;
    } 
 
    if(l <= i && j <= r){
        lazzy[node] = val;
        push(node);
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;
 
        update(lf, i, mid, l, r, val);
        update(rg, mid + 1, j, l, r, val);
 
        segtree[node] = max(segtree[lf], segtree[rg]);
    }
}
 
int query(int node, int i, int j, int l, int r){
    if(lazzy[node] != -1){
        push(node);
    }
 
    if(j < l || i > r){
        return 0;
    }
 
    if(l <= i && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;
 
        return max(query(lf, i, mid, l, r), query(rg, mid + 1, j, l, r));
    }
}
 
int id(int x){
    int pos = upper_bound(con.begin(), con.end(), x) - con.begin();
 
    return pos - 1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(lazzy, -1, sizeof lazzy);
 
    for(int i = 2 ; i < N ; i++){
        llog[i] = llog[i / 2] + 1;
    }
 
    int n, k;
 
    cin >> n >> k;
 
    string s = "";
 
    for(int i = 0 ; i < n ; i++){
        con.push_back((int) s.length());
 
        cin >> si[i];
 
        for(auto u: si[i]){
            s.push_back(u);
        }
        s.push_back('$');
    }
 
    if(k == 1){
        for(int i = 0 ; i < n ; i++){
            long long msz = (int)si[i].length();
            // cout << "antes " << msz << " depois ";
 
            msz = (msz * (msz + 1LL)) / 2LL;
 
            cout << msz << " ";
        }
 
        cout << "\n";
        return 0;
    }
    //build_sa/
    //build lcp;
 
    
    // cout << "s: " << s << endl;
 
    vector< int > p = suffix_array_construction(s);
    
    // cout << "SA:\n";
    // for(auto u: p){
    //     cout << s.substr(u) << endl;
    // }
    vector< int > lcp = lcp_construction(s, p);
 
    build_sparse_table((int)lcp.size(), lcp);
    // cout << "saiu!\n";
    // cout << endl;
 
    cnt[id(p[0])]++;
 
    int sz = 1;
 
    int id1 = id(p[1]);
 
    if(!cnt[id1]){
        sz++;
    }
 
    cnt[id1]++;
 
    int i = 0, j = 1;
 
    while(j < int(s.length()) - 1){
        if(j < int(s.length()) - 1){
            j++;
            auto idj = id(p[j]);
 
            if(!cnt[idj]){
                sz++;
            }
 
            cnt[idj]++;
        }
        if(sz >= k){
            update(1, 1, N, i + 1, j + 1, rmq(i, j - 1));
        }
 
        while(i < j){
            int idi = id(p[i]);
 
            if(cnt[idi] > 1 || sz > k){
                cnt[idi]--;
                if(!cnt[idi])
                    sz--;
            }else{
                break;
            }
 
            i++;
 
            if(sz >= k){
                update(1, 1, N, i + 1, j + 1, rmq(i, j - 1));
            }
        }
    }
 
    assert(s.length() == p.size());
 
    for(int i = 1 ; i <= s.length() ; i++){
        if(s[p[i - 1]] == '$') continue;
 
        int q = query(1, 1, N, i, i);
 
        int idi = id(p[i - 1]);
 
        int pos = p[i - 1] - con[idi];
 
        q = min(q, (int)si[idi].length() - pos);
 
        ans[idi] += (long long) q;
    }
 
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
 
    cout << "\n";
 
    return 0;
}