//26, 10, 2018, 15:25:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
int a[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                scanf("%d", &a[i][j]);
            }
        }

        ll bestl = 0LL, bestc = 0LL;

        for(int i = 0 ; i < m ; i++){
            ll tmp = 0LL;

            for(int j = 0 ; j < n ; j++)
                tmp += a[j][i];

            bestc = max(bestc, tmp);
        }

        for(int j = 0 ; j < n ; j++){
            ll tmp = 0LL;

            for(int i = 0 ; i < m ; i++){
                tmp += a[j][i];
            }

            bestl = max(bestl, tmp);
        }

        printf("%lld\n", 2LL * bestc);
    }
    return 0;
}