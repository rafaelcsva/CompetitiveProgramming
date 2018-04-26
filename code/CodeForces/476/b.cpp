//25, 04, 2018, 14:48:42 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 110;
char tab[N][N];
int n, k;

bool belongsUp(int i, int j){
    if(tab[i][j] != '.'){
        return 0;
    }

    if(i - k < 0){
        return 0;
    }

    for(int t = i, y = 0 ; y < k; t--, y++){
        if(tab[t][j] != '.'){
            
            return 0;
        }
    }

    return 1;
}

bool belongsDown(int i, int j){
    if(tab[i][j] != '.'){
        return 0;
    }

    if(i + k >= n){
        return 0;
    }

    for(int t = i, y = 0 ; y < k; t++, y++){
        if(tab[t][j] != '.'){
            return 0;
        }
    }

    return 1;
}
bool belongsLeft(int i, int j){
    if(tab[i][j] != '.'){
        return 0;
    }

    if(j - k < 0){
        return 0;
    }

    for(int t = i, y = 0 ; y < k; t--, y++){
        if(tab[i][t] != '.'){
            return 0;
        }
    }

    return 1;
}
bool belongsRight(int i, int j){
    if(tab[i][j] != '.'){
        return 0;
    }

    if(i + k >= n){
        return 0;
    }

    for(int t = i, y = 0 ; y < k; t++, y++){
        if(tab[i][t] != '.'){
            return 0;
        }
    }

    return 1;
}

int main(){

    cin >> n >> k;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> tab[i][j];
        }
    }

    pii r = {0, 0};
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int cnt = 0;
            int tmp = 0;
            
            for(int x = 0 ; x <= j ; x++){
                for(int t = x ; t < n ; t++){
                    if(tab[i][t] == '#'){
                        break;
                    }  

                    if(t >= j && (t - x + 1) == k){
                        tmp++;

                        break;
                    }
                }
            }

            for(int x = 0 ; x <= i ; x++){
                for(int t = x ; t < n ; t++){
                    if(tab[t][j] == '#'){
                        break;
                    }

                    if(t >= i && (t - x) + 1 == k){
                        tmp++;
                        break;
                    }
                }
            }

            if(ans < tmp){
                ans = tmp;
                r = {i, j};
            }
        }
    }

    cout << r.first + 1 << ' ' << r.second + 1 << endl;

    return 0;
}