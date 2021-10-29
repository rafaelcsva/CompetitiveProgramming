#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int tab[N][N];
int pref[N][N];
int suf[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            char c;
            cin >> c;

            tab[i][j] = c == '1';
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            pref[i][j] += tab[i][j] + pref[i - 1][j];
        }
    }

    for(int i = n ; i >= 1 ; i--){
        for(int j = 1 ; j <= m ; j++){
            suf[i][j] += tab[i][j] + suf[i + 1][j];
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int sum = 0;

        for(int j = 1 ; j <= m ; j++){
            sum += ((suf[i + 1][j] + pref[i - 1][j]) > 0);
        }

        if(sum == m){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}