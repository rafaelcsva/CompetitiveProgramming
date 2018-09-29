//13, 08, 2018, 15:24:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 110, M = int(1e5);
int a[N];
int n, m;
map< pii, int > cnt, st;
vector< vector < int > > divisors;
vector< int > primes, adj[M];
set< int > left_side;
bool is_composite[M];
int cnt_v;
bool vis[M];
int match[M];

void sieve(){
    for(int i = 2 ; i * i < M ; i++){
        if(!is_composite[i]){
            for(int j = i * i ; j < M ; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 2 ; i < M ; i++){
        if(!is_composite[i]){
            primes.push_back(i);
        }
    }
}

void build(int index, int value){
    for(int u: primes){
        if(u * u > value){
            break;
        }

        int q = 0;

        while(value % u == 0){
            value /= u;
            q++;
        }

        if(q){
            st[{index, u}] = cnt_v;
            cnt[{index, u}] = q;
            divisors[index].push_back(u);
            
            cnt_v += q;
        }
    }

    if(value != 1){
        st[{index, value}] = cnt_v;
        cnt[{index, value}] = 1;
        divisors[index].push_back(value);
        
        cnt_v++;
    }
}

void make(int index1, int index2){
    // printf("processando %d + %d\n", index1, index2);
    
    for(int u: divisors[index1]){
        int k = st[{index1, u}];
        // printf("%d divide o index %d\n", divisors[index1][0], index1);
        
        for(int i = 0 ; i < cnt[{index1, u}] ; i++){
            int l = st[{index2, u}];
            

            for(int j = 0 ; j < cnt[{index2, u}] ; j++){
                // printf("%d -> %d %d\n", index1, index2, u);
                adj[l].push_back(k);
                adj[k].push_back(l);
                l++;
            }

            k++;
        }
    }
}

int aug(int u){
    if(vis[u]){
        return 0;
    }

    vis[u] = 1;

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        // printf("here too\n");
        if(match[v] == -1 || aug(match[v])){
            match[v] = u;
            return 1;
        }
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    
    scanf("%d %d", &n, &m);

    divisors.resize(n + 1);
    memset(match, -1, sizeof match);
    
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);

        build(i, a[i]);
    }
    
    for(int i = 0 ; i < m ; i++){
        int u, v;

        scanf("%d %d", &u, &v);
        u--, v--;
        
        if(u & 1){
            left_side.insert(u);
        }else{
            left_side.insert(v);
        }
        
        make(u, v);
    }

    int mcbm = 0;

    for(int u: left_side){
        for(int i = 0 ; i < divisors[u].size() ; i++){
            int v = divisors[u][i];
            int k = st[{u, v}];

            for(int j = 0 ; j < cnt[{u, v}] ; j++){
                memset(vis, false, sizeof vis);
                // printf("tentando para index %d divisor %d\n", u, v);
                if(aug(k)){
                    mcbm++;
                }
                
                k++;
            }
        }
    }

    printf("%d\n", mcbm);

    return 0;
}