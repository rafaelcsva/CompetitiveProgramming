#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int m[N][N];

int main (){
    int q;

    cin >> q;

    while(q--){
        char c;

        cin >> c;

        if(c == 'U'){
            int xa, ya, xb, yb, d;

            cin >> xa >> ya >> xb >> yb >> d;

            for(int i = xa ; i <= xb ; i++){
                for(int j = ya ; j <= yb ; j++){
                    m[i][j] += d;
                }
            }
        }else{
            int x, y;

            cin >> x >> y;

            cout << m[x][y] << endl;
        }
    }

    return 0;
}