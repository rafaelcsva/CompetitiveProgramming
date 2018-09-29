//16, 08, 2018, 12:31:28 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &a[i]);
        }

        ll best = 0LL;

        for(int i = 0 ; i <= n - k ; i++){
            ll tmp = 0LL;

            for(int j = 0 ; j < k ; j++){
                tmp += a[i + j];
            }

            best = max(best, tmp);
        }

        printf("%lld\n", best);
    }

    return 0;
}