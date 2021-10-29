#include <bits/stdc++.h>

using namespace std;

const int N = 22;
vector< int > adj[N];
int oper[1 << N];

void merge(vector< vector< int > > &v, int p, vector< int > &mans, int cmask){
    if(p == v.size()){
        mans.push_back(cmask);
        return;
    }

    // printf("%d %lu %lu\n", p, v[p].size(), v.size());
    for(auto mmsk: v[p]){
        merge(v, p + 1, mans, cmask | mmsk);
    }

    reverse(v[p].begin(), v[p].end());
}

vector< int > dfs(int u, int ft, int mask){
    // printf("descendo em %d\n", u);
    vector< int > mans;

    vector< vector< int > > soams;

    mans.push_back(mask);

    for(auto v: adj[u]){
        if(v == ft) continue;

        // printf("call %d->%d\n", u, v);
        soams.push_back(dfs(v, u, mask | (1 << u)));
    }

    if(soams.size() == 0){
        mans.push_back(mask | (1 << u));
    }else{
        // printf("fazendo merge para %d\n", u);
        merge(soams, 0, mans, mask | (1 << u));
    }

    // printf("%d, %lu:", u, soams.size());

    // for(auto u: mans){
    //     printf(" %d ", u);
    // }
    // printf("\n");

    return mans;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 1 ; i < n ; i++){
        int v;

        scanf("%d", &v);

        v--;

        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    auto ops = dfs(0, 0, 0);

    // printf("%lu\n", ops.size());
    
    vector< int > oper;

    for(int i = 1 ; i < int(ops.size()) - 1 ; i++){
        int ansc = -1;
        for(int d = 0 ; d < n ; d++){
            int e = 1 << d;

            if((ops[i] & e) != (ops[i + 1] & e)){
                ansc = d;
                break;
            }
        }
        oper.push_back(ansc + 1);
    }

    printf("%lu\n", oper.size());
    for(auto u: oper){
        printf("%d ", u);
    }
    printf("\n");

    return 0;
}