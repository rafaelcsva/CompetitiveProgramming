#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(2e6) + 10;
const ll mod = ll(1e9) + 7LL;

int father[N];
ll sz[N];

int find(int x){
    if(father[x] == x){
        return father[x];
    }

    return father[x] = find(father[x]);
}

void join(int u, int v, ll &ans){
    int x = find(u);
    int y = find(v);

    if(x != y){
        ans += sz[y] * sz[x];
        // printf("%lld\n", sz[y] * sz[x]);
        ans %= mod;

        if(y > x){
            swap(x, y);
        }

        father[x] = y;
        sz[y] += sz[x];
    }
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 1 ; i <= n ; i++){
            sz[i] = 1LL;
            father[i] = i;
        }

        ll prod = 1LL;

        ll ans = (n * (n - 1LL)) / 2LL;
        ans %= mod;

        for(int i = 1 ; i <= m ; i++){
            int a, b;

            scanf("%d %d", &a, &b);

            if(a > b){
                swap(a, b);
            }

            int d = 0;

            while((d = find(b)) > a){
                join(d, d - 1, ans);

                b = d - 1;
            }
            // printf("%lld\n", ans);
            prod = (prod * ans) % mod;
        }

        printf("Case #%d: %lld\n", test, prod);
    }

    return 0;
}