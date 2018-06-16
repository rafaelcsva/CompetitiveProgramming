//31, 05, 2018, 12:20:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e5 + 10);
int answer[N];
int dp[N];

class Domino{
    public:
        int x, h, idx;

        bool operator >(Domino &other){
            return this->x > other.x;
        }

        bool operator <(Domino &other){
            return this->x < other.x;
        }
};

Domino dominos[N];

class SegTree{
    public:
        int nodes[N << 4];

        void update(int node, int i, int j, int l, int r, int v){
            if(i > r || j < l){
                return;
            }

            if(i >= l && j <= r){
                nodes[node] = v;
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                update(left, i, mid, l, r, v);
                update(right, mid + 1, j, l, r, v);
                
                nodes[node] = max(nodes[left], nodes[right]);
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

                return max(query(left, i, mid, l, r), query(right, mid + 1, j, l, r));
            }
        }
};

SegTree segtree;

int binary_search(int start, int end, int v){
    int r = -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(dominos[mid].x == v){
            return mid;
        }

        if(dominos[mid].x < v){
            start = mid + 1;
            r = mid;
        }else{
            end = mid - 1;
        }
    }

    return r;
}

int main(){
    int n;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> dominos[i].x;
        cin >> dominos[i].h;
        dominos[i].idx = i;
    }

    sort(dominos + 1, dominos + 1 + n);

    for(int i = n ; i >= 1 ; i--){
        if(i == n){
            dp[i] = n;
            answer[dominos[i].idx] = 1;
            segtree.update(1, 1, n, n, n, n);
        }else{
            int idx = binary_search(i, n, dominos[i].x + dominos[i].h - 1);

            if(idx == i){
                segtree.update(1, 1, n, i, i, i);
                answer[dominos[i].idx] = 1;
            }else{
                int r = segtree.query(1, 1, n, i + 1, idx);

                segtree.update(1, 1, n, i, i, r);
                answer[dominos[i].idx] = r - i + 1;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        char c = i == n ? '\n' : ' ';
        cout << answer[i] << c;
    }

    return 0;
}