//17, 06, 2018, 17:54:55 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int ll;

typedef unsigned long long ull;
const int N = int(2e5 + 10);
const ll INF = ll(2e9 + 7);
ll v[N];
vector<int>tmp;

class Node{
    public:
        ll mx, mn1 = INF, mn2 = INF;

        Node(){

        }
        
        Node(ll m){
            mx = m;
        }

        Node join(Node &other){

            if(other.mx != INF)
                tmp.push_back(other.mx);

            if(other.mn1 != INF)
                tmp.push_back(other.mn1);
            
            if(other.mn2 != INF)
                tmp.push_back(other.mn2);

            if(this->mx != INF)
                tmp.push_back(this->mx);

            if(this->mn1 != INF)
                tmp.push_back(this->mn1);

            if(this->mn2 != INF)
                tmp.push_back(this->mn2);
                
            Node r;

            sort(tmp.begin(), tmp.end());
            
            r.mx = tmp[tmp.size() - 1];
            
            if(tmp.size() >= 2)
                r.mn1 = tmp[0];

            if(tmp.size() >= 3)
                r.mn2 = tmp[1];

            tmp.clear();
            
            return r;
        }
};
class SegTree{
    public:
        Node nodes[N << 3];

        void build(int node, int i, int j){
            
            if(i == j){
                nodes[node] = Node(v[i]);
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                build(lf, i, mid);
                build(rg, mid + 1, j);

                nodes[node] = nodes[lf].join(nodes[rg]);
            }
        }

        Node query(int node, int i, int j, int l, int r){
            if(i > r || j < l){
                return Node(INF);
            }

            if(i >= l && j <= r){
                return nodes[node];
            }else{
                int lf = node << 1;
                int rg = lf + 1;
                int mid = (i + j) / 2;

                Node lft = query(lf, i, mid, l, r);
                Node rgt = query(rg, mid + 1, j, l, r);
  
                return rgt.join(lft);
            }
        }
};

SegTree segtree;

bool can(Node x){
    return x.mx <= (x.mn1 + x.mn2);
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%ud", &v[i]);
    }

    segtree.build(1, 1, n);

    ull cnt = 2LL * n - 1LL;

    for(int i = 1 ; i <= n - 2 ; i++){
        int st = i + 2, en = n;
        int r = -1;
        
        while(st <= en){
            int mid = (st + en) / 2;

            Node res = segtree.query(1, 1, n, i, mid);

            if(can(res)){
                r = mid;
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }

        if(r != -1){
            cnt += ll(r - i - 1LL);
        }
    }

    printf("%lld\n", cnt);
    
    return 0;
}