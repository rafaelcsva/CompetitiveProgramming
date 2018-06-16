//09, 06, 2018, 11:11:22 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 55;
ll s[N];
ll c[N][N];

void gen(){
    s[1] = s[2] = 1LL;

    for(int i = 3 ; i < N ; i++){
        s[i] = ((6LL * i - 9) * s[i - 1] - (i - 3) * s[i - 2]) / i;
    }

    for(int i = 0 ; i < N ; i++){
        c[i][0] = c[i][i] = 1LL;

        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int main(){
    int n;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    gen();
    
    while(cin >> n){
        n--;
        ll sum = s[n + 1] - c[2 * n][n] / (n + 1);

        cout << sum << endl;
    }

    return 0;
}