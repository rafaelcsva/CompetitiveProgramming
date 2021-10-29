#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long   ll;

const int N = 60;
ll c[N][N];
ll d[N];
int n, k;

ll solve(ll v, int k){
    if(k == 0){
        return 1LL;
    }

    int pos = upper_bound(d, d + n + 1, v) - d;
    pos--;

    if(pos < k){
        return 0LL;
    }else{
        if(2LL * d[pos] <= v){
            return c[pos][k];
        }

        ll add = 0LL;
        if(pos > k){
            add = c[pos - 1][k];
        }
        // printf("temo %lld %d %d\n", v, pos, k);
        // printf("add %lld\n", add);
        // printf("%lld ret\n", v - d[pos]);
        // assert(v >= d[pos]);
        // printf("")

        return add + solve(v - d[pos], k - 1);
    }
}

int main(){
    for(int i = 0 ; i < N ; i++){
        c[i][0] = c[i][i] = 1LL;
        for(int j = 1 ; j < i ; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            assert(c[i][j] > 0LL);
        }
    }

    scanf("%d %d", &n, &k);

    d[0] = 0LL;
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &d[i]);
    }

    sort(d, d + n + 1);

    ll a, b;

    scanf("%lld %lld", &a, &b);

    ll cnt = 0LL;

    // if(k == 1){
    //     for(int i = 1 ; i <= n ; i++){
    //         if(d[i] >= a && d[i] <= b){
    //             cnt++;
    //         }
    //     }
    // }else{
    // printf("%lld - %lld\n", solve(b, k), solve(a - 1, k));
    cnt = solve(b, k) - solve(a - 1LL, k);
    // }

    // assert(cnt >= 0LL);
    printf("%lld\n", cnt);

    return 0;
}