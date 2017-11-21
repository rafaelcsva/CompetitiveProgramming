#include <bits/stdc++.h>

using namespace std;

int a[110][110];

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;

    a[0][0] = m;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == 0 && j == 0)
                continue;
            
            if(j < i){
                a[i][j] = a[i-1][j] - 1;
            }else if(j > i){
                a[i][j] = a[i][j-1] - 1;
            }else{
                a[i][j] = a[i-1][j-1] + k;
            }
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
