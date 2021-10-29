#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int nxt[N];
int a[N];
bool remov[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        set< int > st;
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);

            nxt[i] = (i + 1) % n;
            st.insert(i);
            remov[i] = false;
        }

        vector< int > rem;
        bool changed = true;
        while(changed){
            changed = false;
            set< int > fst;
            for(auto u: st){
                // printf("%d %d\n", u + 1, nxt[u] + 1);
                if(!remov[u] && __gcd(a[u], a[nxt[u]]) == 1){
                    assert(!remov[nxt[u]]);
                    remov[nxt[u]] = true;
                    rem.push_back(nxt[u]);
                    fst.erase(nxt[u]);
                    fst.insert(u);

                    // printf("remov %d add %d\n", nxt[u] + 1, u);
                    while(remov[nxt[u]] && u != nxt[u]){
                        nxt[u] = nxt[nxt[u]];
                        // printf("%d %d\n", u, nxt[u]);
                    }

                    changed = true;
                }
            }

            st = fst;
        }

        printf("%lu", rem.size());

        for(auto u: rem){
            printf(" %d", u + 1);
            remov[u] = false;
        }

        printf("\n");
    }

    return 0;
}