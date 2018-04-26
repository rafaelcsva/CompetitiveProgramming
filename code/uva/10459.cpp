#include <bits/stdc++.h>


using namespace std;

const int N = int(1e5 + 100);
int deep[N];
bool isWorst[N];
vector<vector<int> > adj;
int cl = 0;
int r;

void dfs(int x, int f, int d){
    r = max(d, r);
    deep[x] = d;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int v = adj[x][i];

        if(v != f){
            dfs(v, x, d + 1);
        }
    }
}

int main (){
    int n;

    while(scanf("%d", &n) != EOF){
        adj.clear();
        adj.resize(n + 1);
        memset(isWorst, false, sizeof isWorst);

        for(int i = 1 ; i <= n ; i++){
            int k;

            scanf("%d", &k);

            for(int j = 0 ; j < k ; j++){
                int x;

                scanf("%d", &x);

                adj[i].push_back(x);
            }
        }

        int mn = int(1e9);
        int mx = -1;
        r = 0;
        int x = 0;

        dfs(1, 1 , 0);

        for(int i = 1 ; i <= n ; i++){
            if(deep[i] == r){
                cout << i << ' ' << deep[i] << endl;
                isWorst[i] = true;
                x = i;
            }
        }

        r = 0;
        dfs(x, x, 0);

        for(int i = 1 ; i <= n ; i++){
            if(deep[i] == r){
                isWorst[i] = true;
            }
        }

        printf("Best Roots : ");

        for(int i = 1 ; i <= n ; i++){
            if(deep[i] <= r / 2 + (r % 2)){
                printf(" %d (%d)", i, deep[i]);
            }
        }
        printf("\n");

        printf("Worst Roots :");

        for(int i = 1 ; i <= n ; i++){
            if(isWorst[i]){
                printf(" %d (%d)", i, deep[i]);
            }
        }
        printf("\n");

        for (int i ; i < n ; i++) {
            
        }
    }

    return 0;
}