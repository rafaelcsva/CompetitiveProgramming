//30, 05, 2018, 10:19:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(1e5 + 50010);
int n, len, h;
int a[N], b[N];
typedef multiset<int>   msti;

class MergeTree{
    public:
        msti mst[N << 4];

        void build(int node, int i, int j){
            if(i == j){
                mst[node].insert(a[i]);
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                for(int k = i ; k <= j ; k++){
                    mst[node].insert(a[k]);
                }

                build(left, i, mid), build(right, mid + 1, j);
            }
        }

        bool query(int node, int i, int j, int l, int r){
            if(i > r || j < l){
                return true;
            }

            if(i >= l && j <= r){
                int ini = i - l + 1;
                bool ok = true;

                for(msti::iterator it = mst[node].begin() ; it != mst[node].end() ; it++){
                    if(b[ini] + *it < h){
                        ok = false;
                        break;
                    }

                    ini++;
                }

                return ok;
            }else{
                int left = node << 1;
                int right = left + 1;
                int mid = (i + j) / 2;

                bool lf = query(left, i, mid, l, r);
                bool rg = query(right, mid + 1, j, l, r);

                return lf & rg;
            }
        }
};

MergeTree mergetree;

int main(){
    cin >> n >> len >> h;

    for(int i = 1 ; i <= len ; i++){
        cin >> b[i];
    }

    sort(b + 1, b + 1 + n, greater<int>());

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    mergetree.build(1, 1, n);
    
    int cnt = 0;

    for(int start = 1 ; start <= n - len + 1 ; start++){
        bool res = mergetree.query(1, 1, n, start, start + len - 1);
        int j = 1;
        bool ok = true;

        if(res){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}