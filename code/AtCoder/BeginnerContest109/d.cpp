//08, 09, 2018, 09:37:51 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< pii, pii > ope;
const int N = 600;
int tab[N][N];

vector< ope > operations;
int vi[] = {1, 1, 0, 0};
int vj[] = {0, 0, 1, 1};
int h, w;
bool mark[N][N];

bool ok(int i, int j){
    return i >= 1 && i <= h && j >= 1 && j <= w;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= w ; j++){
            cin >> tab[i][j];
        }
    }

    for(int i = 1 ; i <= h ; i++){
        int st, inc, last;

        if(i & 1){
            st = 1;
            inc = 1;
            last = w + 1;
        }else{
            st = w;
            inc = -1;
            last = 0;
        }

        for(int j = st ; j != last ; j += inc){
            if(mark[i][j] || tab[i][j] % 2 == 0){
                continue;
            }

            int wi = i, wj = j;
            // cout << i << " " << j << " entrou" << endl;
            
            for(int k = i ; k <= h ; k++){
                int stx, incx, lastx;

                if(k & 1){
                    incx = 1, lastx = w + 1;

                    if(k == i){
                        stx = j + 1;
                    }else{
                        stx = 1;
                    }
                }else{
                    incx = -1, lastx = 0;

                    if(k == i){
                        stx = j - 1;
                    }else{
                        stx = w;
                    }
                }

                bool ok = false;

                for(int l = stx ; l != lastx ; l += incx){
                    
                    operations.push_back({{wi, wj}, {k, l}});
                    // cout << "added!" << endl;
                    tab[wi][wj]--;
                    tab[k][l]++;

                    mark[wi][wj] = true;
                    wi = k, wj = l;
                    
                    if(tab[k][l] % 2 == 0){
                        ok = true;
                        break;
                    }
                }

                if(ok){
                    break;
                }
            }
        }
    }

    // cout << " sai aqui oh!" << endl;
    cout << operations.size() << endl;
    
    for(int i = 0 ; i < operations.size() ; i++){
        cout << operations[i].first.first << " " << operations[i].first.second << " " << operations[i].second.first << " " << operations[i].second.second << endl;
    }

    return 0;
}