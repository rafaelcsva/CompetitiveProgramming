//21, 06, 2018, 23:41:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef pair<ll, pii> pipii;
typedef vector<pipii> vi;
typedef pair<ll, int>   pli;
typedef pair<pli, vi>   plivi;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
priority_queue < plivi > pq[N];
ll c[N];
ll pref[N];

class Node{
    public:
        ll sz = 0;
        int idx = 0;

        Node(){

        }
        
        Node(ll v, int id){
            sz = v;
            idx = id;
        }  
};

Node get_best(Node a, Node b){
    if(a.idx <= 0)
        return b;
    if(b.idx <= 0)
        return a;
    
    int idxa = pq[a.idx].top().first.second;
    int idxb = pq[b.idx].top().first.second;

    if(a.sz > b.sz){
        return a;
    }else if(a.sz == b.sz){
        if(idxa > idxb){
            return a;
        }else{
            return b;
        }
    }else{
        return b;
    }
}



class SegTree{
    public:
        Node nodes[N << 3];

        void update(int node, int i, int j, int l, int r, ll v, int idx){
            if(i > r || j < l){
                return;
            }
            
            if(i >= l && j <= r){
                nodes[node] = Node(v, idx);
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                update(lf, i, mid, l, r, v, idx);
                update(rg, mid + 1, j, l, r, v, idx);

                nodes[node] = get_best(nodes[lf], nodes[rg]);
            }
        }

        Node query(int node, int i, int j, int l, int r){
            if(i > r || j < l){
                // cout << "-- " << node << endl;
                return Node(-1, -1);
            }

            if(i >= l && j <= r){
                // cout << nodes[node].idx << endl;
                return nodes[node];
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                Node a = query(lf, i, mid, l, r);
                Node b = query(rg, mid + 1, j, l, r);

                return get_best(a, b);
            }
        }
};

SegTree segtree;
int n;

ll get_most_far(Node rg, Node lf, int i){
    ll a = rg.sz - pref[i - 1];

    if(lf.sz == -1){
        return a;
    }

    ll b = pref[n] - pref[i - 1] + lf.sz;

    if(a > b){
        return a;
    }else if(a < b){
        return b;
    }else{
        int idxa = pq[rg.idx].top().first.second;
        int idxb = pq[lf.idx].top().first.second;
        if(idxa > idxb){
            return a;
        }else{
            return b;
        }
    }
}

Node get_my_best(Node rg, Node lf, int i){
    if(lf.idx <= 0)
        return rg;
    if(rg.idx <= 0)
        return lf;

    int idxa = pq[rg.idx].top().first.second;
    int idxb = pq[lf.idx].top().first.second;
    ll sza = rg.sz - pref[i - 1];
    ll szb = pref[n] - pref[i - 1] + lf.sz;

    if(sza > szb){
        return rg;
    }else if(sza == szb){
        if(idxa > idxb){
            return rg;
        }else{
            return lf;
        }
    }else{
        return lf;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> c[i];
        pq[i].push({{0, i},{{0 ,{i, i}}}});
        pref[i] = c[i] + pref[i - 1];
    }

    for(int i = 1, j = 1 ; i <= n ; i++, j++){
        segtree.update(1, 1, n, i, i, pref[i - 1], i);
    }

    int m;

    cin >> m;

    int id = n + 1;

    for(int i = 0 ; i < m ; i++){
        int t;
        int x, w;

        cin >> t;

        if(t == 1){
            cin >> x >> w;

            Node a = segtree.query(1, 1, n, x, n);
            Node b = segtree.query(1, 1, n, 1, x - 1);

            a = get_my_best(a, b, x);
            // cout << a.idx << endl;
            
            plivi x = pq[a.idx].top();

            x.second.push_back({w, {x.first.second, id}});
            x.first.second = id;
            x.first.first += w;

            pq[a.idx].pop();
            pq[a.idx].push(x);
            
            id++;
             
            segtree.update(1, 1, n, a.idx, a.idx, a.sz + w, a.idx);
        }else if(t == 2){
            cin >> x >> w;

            Node a = segtree.query(1, 1, n, x, x);
        
            pq[a.idx].push({{w, id},{{w ,{id, id}}}});
            
            id++;
            ll d = pref[a.idx - 1];

            segtree.update(1, 1, n, a.idx, a.idx, d + pq[a.idx].top().first.first, a.idx);
        }else if(t == 3){
            cin >> x;

            Node a = segtree.query(1, 1, n, x, n);
            Node b = segtree.query(1, 1, n, 1, x - 1);

            a = get_my_best(a, b, x);

            plivi x = pq[a.idx].top();

            x.first.first -= x.second.back().first;

            x.second.pop_back();
            
            if(x.second.size())
                x.first.second = x.second.back().second.second;

            pq[a.idx].pop();
            
            if(x.second.size()){
                pq[a.idx].push(x);
            }
            
            ll d = pref[a.idx - 1];

            segtree.update(1, 1, n, a.idx, a.idx, d + pq[a.idx].top().first.first, a.idx);
        }else{
            cin >> x;

            Node a = segtree.query(1, 1, n, x, n);
            // cout << "----" << endl;
            Node b = segtree.query(1, 1, n, 1, x - 1);
            
            cout << get_most_far(a, b, x) << endl;
        }
    }

    return 0;
}