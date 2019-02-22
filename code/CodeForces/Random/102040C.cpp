#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long   ll;
typedef pair< int, int >    pii;

const int N = int(1e6 + 10), M = int(1e5);
ll resp[N];
ll cnt[N];
int position[N];
vector< pii > v;
ll segtree[N << 2];
int is_composite[N];
vector< int > primes;
const ll mod = ll(1e7) + 7LL;
const ll inv2 = ll(5e6) + 4LL;
ll dp[N];

void sieve(){
    //printf("N: %d\n", N);
    for(int i = 2 ; i * i < N ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < N ; j += i){
                is_composite[j] = 1;
            }
        }
    }

    for(int i = 2 ; i < N ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
            position[i] = primes.size(); 
        }
    }
}

void build(int node, int i, int j){
  //  assert(node < (N << 2));
    if(i == j){
        segtree[node] = 1LL;
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;

        build(lf, i, mid);
        build(rg, mid + 1, j);

        segtree[node] = segtree[lf] * segtree[rg];
    }
}

void update(int node, int i, int j, int pos, ll val){
    // assert(pos != 0);
    
    if(j < pos || i > pos){
        return;
    }

    if(i == pos && j == pos){
        segtree[node] = val;
    }else{
        int lf = node << 1;
        int rg = lf + 1;
        int mid = (i + j) >> 1;

        update(lf, i, mid, pos, val);
        update(rg, mid + 1, j, pos, val);

        segtree[node] = (segtree[lf] * segtree[rg]) % mod;
    }
}

int main(){
    int n;
    int idx = 0;

    primes.push_back(1);
    sieve();

    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }

        v.push_back({n, idx});
        idx++;
    }

    sort(v.begin(), v.end());

    build(1, 1, M - 1);

    int last = 0;
    //printf("%lu\n", primes.size());

    for(int i = 0 ; i < v.size() ; i++){
        for(int j = last + 1 ; j <= v[i].first ; j++){
            int cur = j;

            for(int t : primes){
                if(t == 1){
                    continue;
                }
                
                if(t * t > cur){
                    break;
                }

                if(cur % t == 0){
                    while(cur % t == 0){
                        cnt[t]++;
                        cur /= t;
                    }

                    ll sum = ((((1LL + cnt[t] + 1LL) * (cnt[t] + 1LL)) % mod) * inv2) % mod;
                    // assert(sum > 0LL);

                    update(1, 1, M - 1, position[t], sum);
                }
            }

            if(cur != 1){
                cnt[cur]++;
                ll sum = ((((1LL + cnt[cur] + 1LL) * (cnt[cur] + 1LL)) % mod) * inv2) % mod;
                // assert(sum > 0LL);
                    
                update(1, 1, M - 1, position[cur], sum);
            }
            
        }

        resp[v[i].second] = segtree[1];
        last = v[i].first;
    }

    // ll best = 0;
    // int besti = 0;
    // ll result = 1LL;

    // for(int i = 1 ; i < N ; i ++){
    //     if(cnt[i] > best){
    //         best = cnt[i];
    //         besti = i;
    //     }

    //     // result = ((((((1LL + cnt[i] + 1LL) * (cnt[i] + 1LL)) % mod) * inv2) % mod) * result) % mod; 
    // }

    // printf("besti = %d (%lld)\n", besti, best);

    //printf("ttt: %lld %d %lld\n", best, besti, cnt[besti]);
    for(int i = 0 ; i < v.size() ; i++){
        // assert(resp[i] > 0LL);

        printf("%lld\n", resp[i]);
    }

    return 0;
}