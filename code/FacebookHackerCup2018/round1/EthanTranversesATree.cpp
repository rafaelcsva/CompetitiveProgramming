//21, 07, 2018, 14:37:52 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 2010;
int L[N], R[N];
int label[N];
int father[N];
vector< int > pre, pos;

int find(int x){
    if(father[x] == x){
        return x;
    }

    return father[x] = find(father[x]);
}

void join(int i, int j){
    int x = find(i), y = find(j);

    if(x != y){
        if(x < y){
            father[y] = x;
        }else{
            father[x] = y;
        }
    }
}

void pos_order(int node){
    if(node == 0){
        return;
    }

    pos_order(L[node]);
    pos_order(R[node]);

    pos.push_back(node);
}

void pre_order(int node){
    if(node == 0){
        return;
    }

    pre.push_back(node);
    pre_order(L[node]);
    pre_order(R[node]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        int n, k;

        cin >> n >> k;

        for(int i = 1 ; i <= n ; i++){
            cin >> L[i] >> R[i];

            father[i] = i;
        }
        
        pos_order(1);
        pre_order(1);
    
        for(int i = 0 ; i < n ; i++){
            join(pos[i], pre[i]);
        }
        
        
        int cnt_disjoint_set = 0;

        for(int i = 1 ; i <= n ; i++){
            if(find(i) == i){
                label[i] = cnt_disjoint_set % k;
                cnt_disjoint_set++;
            }
        }

        cout << "Case #" << test << ": ";

        if(cnt_disjoint_set >= k){
            for(int i = 1 ; i <= n ; i++){
                cout << label[find(i)] + 1;

                if(i == n){
                    cout << endl;
                }else{
                    cout << " ";
                }
            }
        }else{
            cout << "Impossible" << endl;
        }

        pre.clear(), pos.clear();
    }

    return 0;
}