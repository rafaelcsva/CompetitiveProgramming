//12, 11, 2018, 14:58:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5 + 100;
vector< int > adj[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 1 ; i < n ; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    

    return 0;
}