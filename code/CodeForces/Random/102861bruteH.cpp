#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long   ll;

const int N = 60;
ll c[N][N];
ll d[N];
int n, k;

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &d[i]);
    }
    
    ll cnt, a, b;
    cnt = 0LL;

    scanf("%lld %lld", &a, &b);

    for(int m = 0 ; m < (1 << n) ; m++){
        if(__builtin_popcount(m) == k){
            ll sum = 0LL;

            for(int e = 0 ; e < n ; e++){
                int ee = 1 << e;

                if(m & ee){
                    sum += d[e];
                }
            }

            if(sum >= a && sum <= b){
                cnt++;
            }
        }
    }
    printf("%lld\n", cnt);

    return 0;
}