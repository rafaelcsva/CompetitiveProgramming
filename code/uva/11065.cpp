//25, 09, 2018, 22:08:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 70;
int n, k;
int cnt = 0, mx = 0;
int adj[N];

void solve(int mask, int taked, int v){
    if(mask == (1 << n) - 1){
        cnt++;

        mx = max(mx, taked);
    }else{
        for(int i = v ; i < n ; i++){
            if(!(mask & (1 << i))){
                solve(mask | adj[i], taked + 1, i + 1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n ; i++){
            adj[i] |= (1 << i);
        }

        for(int i = 0 ; i < k ; i++){
            int u, v;

            scanf("%d %d", &u, &v);

            adj[u] |= (1 << v);
            adj[v] |= (1 << u);
        }

        cnt = mx = 0;

        solve(0, 0, 0);

        printf("%d\n%d\n", cnt, mx);
        
        memset(adj, 0, sizeof adj);
    }

    return 0;
}