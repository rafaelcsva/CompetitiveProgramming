#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int gauss(vector< bitset< N > > a, int n, int m){
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;

        // cout << "******\n";
        // for(auto u: a){
        //     cout << u << endl;
        // }
    }

    vector<int> ans (m, 0);

    for(int i = 0 ; i < m ; i++){
        if(where[i] != -1){
            ans[i] = a[where[i]][m];
            // cout << "take " << i << " " << ans[i] << "\n";
        }
    }

    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < m ; j++){
            sum += ans[j] * a[i][j];
            sum &= 1;
        }

        if(sum != a[i][m]){
            return 0;
        }
    }

    return 1;
}

vector< int > adj[N];

int main(){
    int p, f;

    scanf("%d %d", &p, &f);

    for(int i = 0 ; i < f ; i++){
        int ui, vi;

        scanf("%d %d", &ui, &vi);

        ui--, vi--;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    vector< bitset< N > > eq;

    for(int i = 0 ; i < p ; i++){
        bitset< N > r;

        for(auto u: adj[i]){
            r[u] = 1;
        }

        if(adj[i].size() & 1){
            r[p] = 0;
            r[i] = 1;            
        }else{
            r[p] = 1;
        }

        eq.push_back(r);
    }

    if(gauss(eq, p, p)){
        printf("Y\n");
    }else{
        printf("N\n");
    }

    return 0;
}