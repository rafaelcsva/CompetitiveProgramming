//28, 07, 2018, 19:23:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 110;
int a[N][N];
int n;
int match[N];
int vis[N];

int aug(int x, int color){
    if(vis[x]){
        return 0;
    }

    vis[x] = 1;

    for(int i = 0 ; i < n ; i++){
        if(a[x][i] == color){
            if(match[i] == -1 || aug(match[i], color)){
                match[i] = x;
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;
    int test = 0;

    while(t--){

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> a[i][j];
            }
        }

        int mcbm = 0;

        for(int color = -n ; color <= n ; color++){
            if(color == 0)
                continue;

            memset(match, -1, sizeof match);

            for(int i = 0 ; i < n ; i++){    
                memset(vis, 0, sizeof vis);

                mcbm += aug(i, color);                
            }    
        }

        cout << "Case #" << test + 1 << ": " << n * n - mcbm << endl;
        test++;
    }

    return 0;
}