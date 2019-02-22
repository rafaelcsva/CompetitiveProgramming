//11, 10, 2018, 16:40:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5100;
int a[N];
int cor[N];
vector< vector< int > > adj;

void dfs(int x){
    cor[x] = 1;

    for(int i = 0 ; i < adj[x].size() ; i++){
        int u = adj[x][i];

        if(cor[u] == 0)
            dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    adj.resize(n + 10);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            int x = __gcd(a[i], a[j]);

            if(x == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int comp = 0;

    for(int i = 0 ; i < n ; i++){
        if(cor[i] == 0){
            comp++;
            dfs(i);
        }
    }

    printf("%d\n", comp);

    return 0;
}