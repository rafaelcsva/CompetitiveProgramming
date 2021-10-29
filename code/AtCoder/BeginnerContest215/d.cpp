#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
const int M = int(1e3);
int a[N];
vector< int > primes;
bool is_composite[N];
bool ver[N];

void sieve(){
    for(int i = 2 ; i < M ; i++){
        if(!is_composite[i]){
            for(int j = i + i ; j < M ; j += i){
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

int main(){
    sieve();

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n ; i++){
        int ai;

        scanf("%d", &ai);

        for(int u: primes){
            if(u * u > ai){
                break;
            }

            if(ai % u == 0){
                ver[u] = true;
                while(ai % u == 0){
                    ai /= u;
                }
            }
        }

        if(ai != 1){
            ver[ai] = true;
        }
    }

    vector< int > ans;

    for(int i = 1 ; i <= m ; i++){
        bool frag = false;
        int ti = i;

        for(int u: primes){
            if(u * u > ti){
                break;
            }

            if(ti % u == 0){
                if(ver[u]){
                    frag = true;
                }

                while(ti % u == 0){
                    ti /= u;
                }
            }
        }

        if(ti != 1){
            frag |= ver[ti];
        }

        if(!frag){
            ans.push_back(i);
        }
    }

    printf("%lu\n", ans.size());

    for(auto u: ans){
        printf("%d\n", u);
    }

    return 0;
}