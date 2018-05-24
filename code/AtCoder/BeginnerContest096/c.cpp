//05, 05, 2018, 09:09:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = 100;
char tab[N][N];
int vi[] = {0, 0, -1, 1}, vj[] = {1, -1, 0, 0};
int n, m;

bool ok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && tab[i][j] == '#';
}

int main(){
    
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> tab[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(tab[i][j] == '#'){
                bool flag = false;

                for(int k = 0 ; k < 4 ; k++){
                    int ti = vi[k] + i, tj = j + vj[k];

                    if(ok(ti, tj)){
                        flag = true;
                    }
                }

                if(!flag){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}