//15, 04, 2019, 12:39:43 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10;
int segtree[N << 2];
int lazzy[N << 2];

void shift(int node){
    int lf = node << 1;
    int rg = lf + 1;

    segtree[node] += lazzy[node];
    lazzy[lf] += lazzy[node];
    lazzy[rg] += lazzy[node];
    
    lazzy[node] = 0;
}

void update(int node, int i, int j, int l, int r, int s){
    if(lazzy[node]){
        shift(node);
    }

    if(i > r || j < l){
        return;
    }

    if(i >= l && j <= r){
        lazzy[node] += s;
        shift(node);
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        update(lf, i, mid, l, r, s);
        update(rg, mid + 1, j, l, r, s);

        segtree[node] = max(segtree[lf], segtree[rg]);
    }
}

int query(int node, int i, int j, int l, int r){
    if(lazzy[node]){
        shift(node);
    }

    if(i > r || j < l){
        return 0LL;
    }

    if(i >= l && j <= r){
        return segtree[node];
    }else{
        int mid = (i + j) >> 1;
        int lf = node << 1;
        int rg = lf + 1;

        return query(lf, i, mid, l, r) + query(rg, mid + 1, j, l, r);
    }
}

ll tmp[N];
ll a[N];
map< ll, vector< int > > mp;
map< ll, int > pt;

class DejaVu{
    public:
    int mostDejaVus(int N, int seed, int R, vector< int > d){
        N++;
        ll n = ll(N);
        ll s = ll(seed);
        ll r = ll(R);

        tmp[0] = s;

        for(int i = 1 ; i < n ; i++){
            tmp[i] = (tmp[i-1] * 1664525LL + 1013904223LL) % 4294967296LL;
        }

        for(int i = 1 ; i <= n ; i++){
            a[i] = d[i - 1];

            mp[a[i]].push_back(i);
        }

        for(int i = 1 ; i <= n ; i++){
            vector< int > vv = mp[a[i]];

            if(i == vv[0]){
                mp[a[i]].push_back(n + 1);
                vv.push_back(n + 1);

                if(vv.size() > 2){
                    update(1, 1, N - 1, vv[1], vv[2] - 1, 1);
                }
            }
        }

        int best = query(1, 1, N - 1, 1, N - 1);

        for(int i = 1 ; i <= n ; i++){
            vector< int > vv = mp[a[i]];
            ll ai = a[i];

            if(pt[ai] + 2 < vv.size()){
                update(1, 1, N - 1, vv[pt[ai] + 1], vv[pt[ai] + 2], -1);
                pt[ai]++;

                if(pt[ai] + 2 < vv.size()){
                    update(1, 1, N - 1, vv[pt[ai] + 1], vv[pt[ai] + 2] - 1, 1);
                }
            }

            best = max(best, query(1, 1, N - 1, 1, N - 1));
        }

        return best;
    }
};

int main(){
    int a = 10;

    cout << 1000000000000L * a << endl;
    DejaVu test;

    cout << test.mostDejaVus(10, 10, 10, {0, 1, 2, 0, 4, 4, 7, 7, 8 , 0}) << endl;
}