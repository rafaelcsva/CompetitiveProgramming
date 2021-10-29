#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll E = ll(4000);

const int N = 100;
ll n[N];
ll p[N];
int m;

bool solve(ll val, ll sum){
    ll msum = 0LL;

    for(int i = 0 ; i < m ; i++){
        ll cnti = 0LL;
        while(val % p[i] == 0LL){
            cnti++;
            val /= p[i];
        }

        if(cnti > n[i]){
            return false;
        }

        msum += p[i] * cnti;
    }

    return msum == sum && val == 1LL;
}

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        scanf("%d", &m);

        ll sum = 0LL;
        for(int i = 0 ; i < m ; i++){
            scanf("%lld %lld", &p[i], &n[i]);
            sum += p[i] * n[i];
        }

        printf("Case #%d: ", test);
    
        ll ans = 0LL;

        for(ll d = 2LL ; d < min(E, sum) ; d++){
            // printf("%lld %lld\n", d, sum);
            if(solve(sum - d, d)){
                ans = sum - d;
                // printf("finished!\n");
                break;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}