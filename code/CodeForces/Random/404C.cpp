//30, 07, 2018, 20:43:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< vector< int > >cap, adj;
vector< pii >edges;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    scanf("%d %d", &n, &k);
    
    cap.resize(n + 1), adj.resize(n + 1);

    for(int i = 0 ; i < n ; i++){
        int x;

        scanf("%d", &x);

        cap[x].push_back(i + 1);

        if(x > n){
            printf("-1\n");
            return 0;
        }
    }

    if(cap[0].size() > 1){
        printf("-1\n");
        return 0;
    }

    for(int i = 1 ; i <= n ; i++){
        if(cap[i].size() > 0){
            int j = 0, t = 0;
            int sz = cap[i - 1].size();

            while(j < cap[i - 1].size() && t < cap[i].size()){
                int ej = cap[i - 1][j];
                int ei = cap[i][t];

                t++;
                j = (j + 1) % sz;

                adj[ej].push_back(ei);
                adj[ei].push_back(ej);

                if(adj[ej].size() > k){
                    printf("-1\n");
                    return 0;
                }

                if(adj[ei].size() > k){
                    printf("-1\n");
                    return 0;
                }

                edges.push_back({ei, ej});
            }

            if(t != cap[i].size()){
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%lu\n", edges.size());

    for(pii u: edges){
        printf("%d %d\n", u.first, u.second);
    }

    return 0;
}