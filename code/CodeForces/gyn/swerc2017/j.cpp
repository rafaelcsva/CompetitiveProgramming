//10, 08, 2018, 15:51:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll a[N], b[N];
ll sum[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);

        sum[i % 3] += a[i];
    }

    ll white = 0LL, yellow = 0LL, pink = 0LL;
    int w = 0, y = 1, p = 2;
    
    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &b[i]);

        white += b[i] * sum[w];
        yellow += b[i] * sum[y];
        pink += b[i] * sum[p];

        w--;
        y--;
        p--;

        w = (w + 3) % 3;
        y = (y + 3) % 3;
        p = (p + 3) % 3;
    }

    printf("%lld %lld %lld\n", yellow, pink, white);
    
    return 0;
}