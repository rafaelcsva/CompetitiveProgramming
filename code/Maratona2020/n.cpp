#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long   ll;
typedef pair< int, int >     pii;

const int N = 31622776 + 10;
const int M = int(2e3) +100;
int lp[N+1];
vector< ll > primes;
vector< pii > adj[N];
ll sum[M];
ll a[M];
ll ans[M];

void sieve(){
    for (int i=2; i< N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        primes.push_back (i);
    }
    for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
        lp[i * primes[j]] = primes[j];
    }
}

int main(){
    sieve();
    // printf("%lu\n", primes.size());

    int m, n, k;

    scanf("%d %d %d", &m, &n, &k);
    
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }

    for(int i = 0 ; i < k ; i++){
        int l, r, d;

        scanf("%d %d %d", &l, &r, &d);
        if(sum[l] == 0)
            sum[l] += a[r];
            
        adj[r].push_back({l, d});
    }

    int j = 0;
    int i = 1;

    while(j < primes.size()){
        while(i <= m && j < primes.size()){
            if(sum[i] % primes[j] == 0LL){
                ans[i] = primes[j];
                break;
            }

            j++;
        }

        i++;
        j++;
    }

    for(int i = 1 ; i <= n ; i++){
        int pt = -1;
        // printf("%lu\n", adj[i].size());

        for(auto u: adj[i]){
            // printf("%d %d\n", i, u.first);
            if(ans[u.first]){
                // printf("entrei %d %d\n", i, u.first);
        
                while(u.second){
                    a[i] /= ans[u.first];
                    u.second--;
                }
            }else{
                pt = u.first;
            }
        }

        // printf("%lld\n", a[i]);

        if(pt != -1){
            ans[pt] = a[i];
        }
    }

    for(int i = 1 ; i <= m ; i++){
        assert(ans[i] != 0);
        printf("%lld ", ans[i]);
    }

    printf("\n");

    return 0;
}