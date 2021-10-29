#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int mark[N][N];
char tab[N][N];

int main(){
    int t;

    cin >> t;

    while(t--){
        int n, m, k;

        cin >> n >> m >> k;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin >> tab[i][j];
            }
        }

        k++;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(tab[i][j] == '*'){
                    int lin = i;
                    int col1 = j;
                    int col2 = j;
                    int d = 0;

                    while(col1 >= 0 && col2 < m && lin >= 0){
                        if(tab[lin][col1] != '*' || tab[lin][col2] != '*'){
                            break;
                        }

                        lin--;
                        col1--;
                        col2++;
                        d++;
                    }

                    col1 = j;
                    col2 = j;
                    lin = i;

                    if(d >= k){
                        while(d){
                            mark[lin][col1] = mark[lin][col2] = 1;
                            col1--;
                            col2++;
                            lin--;
                            d--;
                        }
                    }
                }
            }
        }

        bool frag = false;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(tab[i][j] == '*' && !mark[i][j]){
                    frag = true;
                }

                mark[i][j] = 0;
            }
        }

        if(frag){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }

    return 0;
}