//04, 03, 2019, 10:46:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
ll dp1[N][2];
ll dp2[N];
int last[2];
int a[N];
const ll mod = ll(1e9) + 7LL;
ll bit[2][N];
vector< int > ind[2];

void MOD(ll &x){
    if(x >= mod){
        x -= mod;

        if(x >= mod){
            x -= mod;
        }
    }

    if(x < 0LL){
        x += mod;
    }

    assert(0LL <= x && x < mod);
}

int LSOne(int x){
    return x & (-x);
}

void update(int x, ll *bit, ll value){
    while(x < N){
        bit[x] += value;
        MOD(bit[x]);
        x += LSOne(x);
    }
}

ll query(int x, ll *bit){
    ll sum = 0LL;

    while(x > 0){
        sum += bit[x];
        MOD(sum);
        x -= LSOne(x);
    }

    return sum;
}

ll rsq(int l, int r, ll *bit){
    assert(l <= r);
    // if(l > r){
    //     printf("%d, %d\n", l, r);
    //     exit(0);
    // }

    ll x = query(r, bit) - query(l - 1, bit);
    MOD(x);

    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }

        dp1[1][0] = 1LL;

        for(int i = 2 ; i <= n ; i++){
            dp1[i][0] = dp1[i - 1][0];

            if(i >= 3){
                if(a[i - 2] == 2){
                    dp1[i][0] += dp1[i - 2][0] + dp1[i - 2][1];
                }

                MOD(dp1[i][0]);
            }

            if(a[i - 1] == 2 && i < n){
                dp1[i][1] = dp1[i - 1][0];
            }else{
                dp1[i][1] = 0LL;
            }
        }

        ll sum_odd = 0LL, sum_even = 0LL;
        ll tot = 0LL;
        last[0] = last[1] = 0;

        for(int i = 1 ; i <= n ; i++){
            int u = last[!(i & 1)];

            if(a[i - 1] == 1){
                u = i - 1;
            }

            update(i, bit[i & 1], dp1[i][0]);

            tot += rsq(max(u - 1, last[i & 1] + 1), i, bit[i & 1]);
            MOD(tot);

            if(a[i] == 2 && i > 2){
                tot += rsq(max(last[i & 1] - 1, last[!(i & 1)] + 1), i - 2, bit[!(i & 1)]);
                MOD(tot);
            }

            if(a[i - 1] == 1){
                last[!(i & 1)] = i - 1;
            }
        }

        assert(tot >= 0LL);

        printf("%lld\n", tot);
        memset(bit, 0LL, sizeof bit);
    }
    
    return 0;
}