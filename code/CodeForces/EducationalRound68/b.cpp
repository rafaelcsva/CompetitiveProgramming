#include <bits/stdc++.h>

using namespace std;

const int N = int(5e5);
int row[N], col[N];

int main(){
    int t;

    cin  >> t;

    while(t--){
        int n,m;

        cin >> n >> m;

        vector< vector< char > > tab;

        tab.resize(n);

        int ans = n + m - 1;

        for(int i = 0 ; i < n ; i++){
            tab[i].resize(m);
            for(int j = 0 ; j< m ; j++){
                cin >> tab[i][j];
                row[i] += (tab[i][j] == '*');
                col[j] += (tab[i][j] == '*');
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < m ; j++){
                int tot = n + m - 1 - row[i] - col[j];

                if(tab[i][j] == '*'){
                    tot++;
                }

                ans = min(ans, tot);
            }
        }

        printf("%d\n", ans);

        for(int i = 0 ; i < n ; i++){
            row[i] = 0;
        }    

        for(int j = 0 ; j < m ; j++){
            col[j] = 0;
        }
    }

    return 0;
}