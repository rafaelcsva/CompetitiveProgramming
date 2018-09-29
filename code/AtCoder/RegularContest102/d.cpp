//01, 09, 2018, 09:27:45 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, pii>  pipii;

vector< pipii > edges;
const int vertices = 20;
const int N = 20;
int digits[N];

void dfs(int u, int deep, int cost, int mx, int dg, int l){
    // cout << q << endl;
    if(dg == l){
        for(int i = 0 ; i < 1; i++){
            edges.push_back({cost, {u, N}});
        }

        return;
    }

    if(cost == 0){
        for(int i = 0 ; i < 2 ; i++){
            edges.push_back({0, {u, u + 1}});
        }
    }

    dfs(u + 1, deep + 1, cost, mx, dg, l * 2);
}

int fact(int dg, int t){
    while(t){
        dg *= 10;
        t--;
    }

    return dg;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l;

    scanf("%d", &l);

    int cost = 0;
    int d = 0;

    // while(l){
    //     digits[d] = l % 10;
    //     d++;
    //     l /= 10;
    // }
    
    for(int i = N - 1 ; i >= 0 ; i--){
        int e = 1 << i;
        
        if(l & e){
            // int st = int(edges.size());
            dfs(1, 0, cost, i, e, 1);
            // int e = int(edges.size());

            // printf("com %d adicionou %d\n", fact(digits[i], i), e - st);
            cost += 2;
        }
    }
    
    printf("%d %lu\n", N, edges.size());
    
    for(int i = 0 ; i < edges.size() ; i++){
        pipii u = edges[i];

        printf("%d %d %d\n", u.second.first, u.second.second, u.first);    
    }

    return 0;
}