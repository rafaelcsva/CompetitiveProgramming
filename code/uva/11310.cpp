//09, 06, 2018, 11:25:28 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned long long ll;

const int N = 50;
ll c[N][N];

void pascal(){
    for(int i = 0 ; i < N ; i++){
        c[i][0] = c[i][i] = 1LL;

        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

ll fast_pow(ll n, int j){
    if(j == 0LL)
        return 1LL;

    if(j == 1LL)
        return n;

    ll r = fast_pow(n, j / 2);

    r *= r;

    if(j % 2)
        r *= n;

    return r;        
}

int main(){
    int t;

    pascal();

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;

    while(t--){
        int n;

        cin >> n;

        ll tot = 0LL;

        for(int i = 0 ; i <= n ; i++){//'o'
            for(int j = 0 ; j <= n ; j++){//'o' + 'L'
                for(int k = 0 ; k <= n ; k++){//'L' + 'L'
                    if(i + j * 2 + k * 3 == n){
                        ll rest = n - j * 2LL;
                        // cout << i << ' ' << j << ' ' << k << ' ' << c[j + rest][j] * fast_pow(4LL, j) * c[n - 2LL * j - 3LL * k + k][k] * fast_pow(4LL, k)<< endl;
                        tot += c[i + j + k][j] * fast_pow(4LL, j) * c[i + k][k] * fast_pow(2LL, k);
                    }
                }
            }
        }

        cout << tot << endl;
    }

    return 0;
}