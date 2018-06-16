//28, 05, 2018, 20:51:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e5 + 10);
int v[N];

class SegTree{
    public:
        int nodes[N << 4];

        void build(int node, int i, int j){
            if(i == j){
                nodes[node] = v[i];
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                build(left, i, mid);
                build(right, mid + 1, j);
                
                nodes[node] = __gcd(nodes[left], nodes[right]);
            }
        }

        int query(int node, int i, int j, int l, int r){
            if(i > r || j < l){
                return 0;
            }

            if(i >= l && j <= r){
                return nodes[node];
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                int lft = query(left, i, mid, l, r);
                int rgt = query(right, mid + 1, j, l, r);

                return __gcd(lft, rgt);
            }
        }
};

class MergeTree{
    public:
        vector<int>nodes[N << 4];
        
        void build(int node, int i, int j){
            if(i == j){
                nodes[node].push_back(v[i]);
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                for(int k = i ; k <= j ; k++){
                    nodes[node].push_back(v[k]);
                }

                sort(nodes[node].begin(), nodes[node].end());

                build(left, i, mid);
                build(right, mid + 1, j);
            }
        }

        int query(int node, int i, int j, int l, int r, int v){
            if(i > r || j < l){
                return 0;
            }

            if(i >= l && j <= r){
                vector<int>::iterator ub, lb;
                // cout << "query in " << i << ' ' << j << " gives the value " ;

                ub = upper_bound(nodes[node].begin(), nodes[node].end(), v);
                lb = lower_bound(nodes[node].begin(), nodes[node].end(), v);

                // cout << int(ub - lb) << endl;
                return int(ub - lb);
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                return query(left, i, mid, l, r, v) + query(right, mid + 1, j, l, r, v);
            }
        }
};

SegTree segtree;
MergeTree mergetree;

int main(){
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> v[i];
    }

    segtree.build(1, 1, n);
    mergetree.build(1, 1, n);

    cin >> m;

    for(int i = 1 ; i <= m ; i++){
        int l, r;

        cin >> l >> r;
        int t = r - l + 1;
        
        int g = segtree.query(1, 1, n, l, r);

        cout << t - mergetree.query(1, 1, n, l, r, g) << endl;
    }

    return 0;
}