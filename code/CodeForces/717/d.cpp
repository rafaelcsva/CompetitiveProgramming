#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
const int K = 20;
int a[N];
int dp[N];
int sp[N][K];
bool is_composite[N];
vector< int > ind[N], fact[N];
vector< int > primes;

void sieve(){
    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

void build(int n){
    for(int i = 1 ; i <= n ; i++){
        sp[i][0] = dp[i];
    }

    for(int k = 0 ; k < K ; k++){
        sp[n + 1][k] = n + 1;
    }

    for(int k = 1 ; k < K ; k++){
        for(int i = 1 ; i <= n ; i++){
            sp[i][k] = sp[sp[i][k - 1]][k - 1];
        }
    }
    // printf("build end!\n");
}

int query(int l, int r){
    int st = l;
    int ans = 1;

    for(int k = K - 1 ; k >= 0 ; k--){
        if(sp[st][k] <= r){
            // printf("+ %d %d %d\n", st, k, sp[st][k]);
            // break;
            st = sp[st][k];
            ans += (1 << k);
            k = K;
        }
    }

    return ans;
}

int main(){
    sieve();
    int n, q;

    scanf("%d %d", &n, &q);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    
        for(auto u: primes){
            if(u * u > a[i]){
                break;
            }

            if(a[i] % u == 0){
                ind[u].push_back(i);
                fact[i].push_back(u);

                while(a[i] % u == 0){
                    a[i] /= u;
                }
            }
        }

        if(a[i] != 1){
            ind[a[i]].push_back(i);
            fact[i].push_back(a[i]);
        }
    }

    for(int i = 0 ; i < N ; i++){
        ind[i].push_back(n + 1);
    }

    dp[n + 1] = n + 1;

    for(int i = n ; i >= 1 ; i--){
        int ans = n + 1;
        for(auto u: fact[i]){
            int pos = *upper_bound(ind[u].begin(), ind[u].end(), i);
            ans = min(ans, pos);
        }

        dp[i] = min(ans, dp[i + 1]);
        // printf("%d %d\n", i, dp[i]);
    }

    build(n);
    while(q--){
        int l, r;

        scanf("%d %d", &l, &r);

        printf("%d\n", query(l, r));
    }

    return 0;
}