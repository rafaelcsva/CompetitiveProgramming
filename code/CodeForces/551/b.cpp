//13, 04, 2019, 11:20:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
int col[N], lin[N];
int ma[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;

    cin >> n >> m >> h;

    for(int i = 0 ; i < m ; i++){
        cin >> col[i];
    }

    for(int i = 0 ; i < n ; i++){
        cin >> lin[i];
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> ma[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(ma[i][j] && lin[i] <= col[j]){
                ma[i][j] = lin[i];
            }else if(ma[i][j] && col[j] <= lin[i]){
                ma[i][j] = col[j];
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}