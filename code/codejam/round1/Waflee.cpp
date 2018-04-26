//13, 04, 2018, 22:10:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
const int N = 110;
typedef pair<int, int> pii;
typedef long long ll;
int sum[N][N];
char t[N][N];
int col[N];
int r, c, h, v;

bool isPossible(int c, int l, int qtd){
    if(l > r){
        return false;
    }

    if(c == h){
        return true;
    }
    

    for(int i = l ; i <= r ; i++){
        bool ok = true;
        
        for(int j = 0 ; j <= v ; j++){
            int cur = sum[i][col[j + 1]] - sum[l - 1][col[j + 1]] - (sum[i][col[j]] - sum[l - 1][col[j]]);
            
            if(cur != qtd){
                ok = false;
                break;
            }
        }

        if(ok){
            if(isPossible(c + 1, i + 1, qtd)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int g;
    int test = 1;
    
    cin >> g;

    while(g--){

        cin >> r >> c >> h >> v;

        int tot = 0;

        for(int i = 1 ; i <= r ; i++){
            for(int j = 1 ; j <= c ; j++){
                cin >> t[i][j];
                tot += t[i][j] == '@';
            }
        }

        if(tot % ((h + 1) * (v + 1)) != 0){
            cout << "Case #" << test++ << ": IMPOSSIBLE" << endl;
            continue;
        }
        int qtd = tot / ((v + 1));
        int coef = tot / ((v + 1) * (h + 1));
        
        for(int i = 1 ; i <= c ; i++){
            for(int j = 1 ; j <= r ; j++){
                sum[j][i] = (t[j][i] == '@') + sum[j - 1][i];
            }
        }

        for(int i = 1 ; i <= r ; i++){
            for(int j = 1 ; j <= c ; j++){
                sum[i][j] += sum[i][j - 1];
            }
        }

        int l = 0;
        int x = 1;

        for(int j = 1 ; j <= c; j++){
            int cur = sum[r][j] - sum[r][l];

            if(cur == qtd){
                col[x++] = j;
                l = j;
            }    
        }

        x--;
        if(x != v + 1 && tot != 0){
            cout << "Case #" << test++ << ": IMPOSSIBLE" << endl;
            continue;
        }
        
        if(isPossible(0, 1, coef)){
            cout << "Case #" << test++ << ": POSSIBLE" << endl;
        }else{
            cout << "Case #" << test++ << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}