//27, 08, 2018, 13:36:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
char t[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> t[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int side_len = 0;
            int tj = j;

            while(tj < m && t[i][tj] == 'B'){
                side_len++;
                tj++;
            }

            if(side_len){
                cout << i + side_len / 2 + 1 << ' ' << j + side_len / 2 + 1 << endl;
                return 0;
            }
        }
    }
    
    return 0;
}