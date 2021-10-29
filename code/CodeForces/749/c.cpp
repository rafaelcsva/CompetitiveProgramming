#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > tab;
const int N = int(1e6) + 10;
int mark[N];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    tab.resize(n);

    for(int i = 0 ; i < n ; i++){
        for(int j =0  ; j < m ; j++){
            char xi;

            scanf("\n%c", &xi);

            tab[i].push_back(xi == 'X');
        }
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m - 1 ; j++){
            if(tab[i][j] && tab[i - 1][j + 1]){
                mark[j] = 1;
            }
        }
    }

    vector< int > rows;

    for(int i = 0 ; i < m ; i++){
        if(mark[i]){
            // printf("%d is marked!\n", i);
            rows.push_back(i);
        }
    }

    int q;

    scanf("%d", &q);

    while(q--){
        int x1, x2;

        scanf("%d %d", &x1, &x2);

        x1--, x2--;

        auto u = lower_bound(rows.begin(), rows.end(), x1);

        if(u == rows.end() || *u >= x2){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}