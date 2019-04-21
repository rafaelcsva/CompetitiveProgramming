//16, 03, 2019, 10:33:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 100);
int a[2][N];
int tmp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[0][i];
    }

    for(int i = 1 ; i <= n ; i++){
        cin >> a[1][i];
    }

    int b = 0;

    for(int i = 1 ; i <= k - 2 ; i++){
        for(int j = 1 ; j <= n ; j++){
            tmp[a[b][j]] = a[!b][j];
        }

        for(int j = 1 ; j <= n ; j++){
            swap(a[b][j], tmp[j]);
        }

        if(i != k - 2)
            b = !b;
    }

    for(int i = 1 ; i <= n ; i++){
        cout << a[b][i] << " ";
    }

    cout << endl;
    
    return 0;
}