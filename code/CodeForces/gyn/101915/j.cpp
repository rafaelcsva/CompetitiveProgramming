//28, 11, 2018, 09:37:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

ll n, w, l;

struct Circle{
    ll x, y, r;
};

const int N = 1010;
Circle circles[N];
vector< int > adj[N];
int bel[N];
ll mnx[N], mxx[N];

void dfs(int u, int comp){
    bel[u] = comp;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];

        if(bel[v] == 0){
            dfs(v, comp);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        cin >> n >> w >> l;

        for(int i = 0 ; i < n ; i++){
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                ll dx = abs(circles[i].x - circles[j].x);
                ll dy = abs(circles[i].y - circles[j].y);
                ll r = circles[i].r + circles[j].r;

                if(dx * dx + dy * dy <= r * r){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int comp = 0;

        for(int i = 0 ; i < n ; i++){
            if(bel[i] == 0){
                comp++;
                mnx[comp] = 1e13;
                mxx[comp] = -1e13;
                dfs(i, comp);
            }
        }

        for(int i = 0 ; i < n ; i++){
            mnx[bel[i]] = min(mnx[bel[i]], circles[i].x - circles[i].r);
            mxx[bel[i]] = max(mxx[bel[i]], circles[i].x + circles[i].r);
        }

        int backpack = 0;

        for(int i = 1 ; i <= comp ; i++){
            if(mnx[i] <= 0 && mxx[i] >= w){
                backpack++;
            }
        }

        cout << backpack << endl;

        memset(bel, 0, sizeof bel);

        for(int i = 0 ; i < n ; i++){
            adj[i].clear();
        }
    }

    return 0;
}