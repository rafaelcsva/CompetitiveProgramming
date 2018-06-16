//24, 05, 2018, 14:20:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(1e5 + 2);
const int M = 42;
ll v[N];

class Node{

    public:
        int bits[M];
        int lazy = 0;

        Node(int x, int l = 0){
            bitset<M>bst(x);
            lazy = l;

            for(int i = 0 ; i < M ; i++){
                this->bits[i] = bst[i];
            }
        }

        Node(){
            
        }
        
        Node operator + (Node other){ 
            for(int i = 0 ; i < M ; i++){
                other.bits[i] = this->bits[i] + other.bits[i];
            }

            return other;
        }

        Node xxor(Node other, int t){
            
            for(int i = 0 ; i < M ; i++){
                if(this->bits[i])
                    other.bits[i] = t - other.bits[i];
            }

            return other;
        }

        ll getSum(){
            ll sum = 0;

            for(ll i = 0 ; i < M ; i++){
                sum += (1LL << i) * ll(this->bits[i]);
            }

            return sum;
        }

        int print(){
            for(int i = M - 1 ; i >= 0 ; i--){
                cout << this->bits[i];
            }

            cout << endl;
        }
};

class Segtree{
    Node nodes[N << 3];

    public:
        void shift(int node, int t){
            Node tmp = Node(nodes[node].lazy);
            
            nodes[node] = tmp.xxor(nodes[node], t);
            
            int left = node << 1;
            int right = left + 1;

            nodes[left].lazy ^= nodes[node].lazy;
            nodes[right].lazy ^= nodes[node].lazy;

            nodes[node].lazy = 0;
        }

        void build(int node, int i, int j){
            if(i == j){
                
                nodes[node] = Node(v[i]);

                // nodes[node].print();
                
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                build(left, i, mid);
                build(right, mid + 1, j);

                nodes[node] = nodes[left] + nodes[right];
            }
        }

        Node query(int node, int i, int j, int l, int r){
            if(nodes[node].lazy){
                shift(node, j - i + 1);
            }

            if(i > r || j < l){
                return Node(0, -1);
            }

            if(i >= l && j <= r){
                
                // nodes[node].print();
                return nodes[node];
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                Node lf = query(left, i, mid, l, r);
                Node rg = query(right, mid + 1, j, l, r);

                if(lf.lazy == -1){
                    return rg;
                }else if(rg.lazy == -1){
                    return lf;
                }

                return lf + rg;
            }
        }

        void update(int node, int i, int j, int l, int r, ll x){
            if(nodes[node].lazy){
                shift(node, j - i + 1);
            }

            if(i > r || j < l){
                return;
            }

            if(i >= l && j <= r){
                nodes[node].lazy = x;
                shift(node, j - i + 1);
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                update(left, i, mid, l, r, x);
                update(right, mid + 1, j, l, r, x);

                nodes[node] = nodes[left] + nodes[right];
            }
        }
};

Segtree segtree;

int main(){
    int n;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i];
    }

    int m;

    segtree.build(1, 1, n);
    
    cin >> m;

    for(int i = 0 ; i < m ; i++){
        int t, l, r;

        cin >> t >> l >> r;
        
        if(t == 1){
           Node res = segtree.query(1, 1, n, l, r);

           cout << res.getSum() << endl;
        }else{
            int x;

            cin >> x;

            segtree.update(1, 1, n, l, r, x);
        }
    }

    return 0;
}