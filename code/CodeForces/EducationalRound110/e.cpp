#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = int(3e5) + 10;
const int D = 20;
int father[N][D];
ll a[N], c[N];

void get_ans(int u, ll &qtd, ll &ans){
    if(a[u] == 0LL){
        return;
    }

    if(u != 0){
        for(int d = D - 1 ; d >= 0 && qtd ; d--){
            if(a[father[u][d]]){
                get_ans(father[u][d], qtd, ans);
            }
        }
    }

    if(qtd){
        ll mn = min(qtd, a[u]);

        qtd -= mn;
        a[u] -= mn;
        ans += c[u] * mn;
    }
}

int main(){
    int q, a0, c0;

    scanf("%d %lld %lld", &q, &a[0], &c[0]);

    for(int i = 1 ; i <= q ; i++){
        int ti;

        scanf("%d", &ti);

        if(ti == 1){
            scanf("%d %lld %lld", &father[i][0], &a[i], &c[i]);

            for(int d = 1 ; d < D ; d++){
                father[i][d] = father[father[i][d - 1]][d - 1];
            }
        }else{
            int vi;
            ll wi;

            scanf("%d %lld", &vi, &wi);
            
            ll twi = wi;
            ll ans = 0LL;
            get_ans(vi, wi, ans);

            printf("%lld %lld\n", twi - wi, ans);
            fflush(stdout);
        }
    }

    return 0;
}