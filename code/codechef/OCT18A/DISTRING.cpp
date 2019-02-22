//11, 10, 2018, 17:18:09 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
const ll PRIME1 = 743, PRIME2 = 137, mod = 1e9 + 7;
int a[N][N];
ll pre1[N][N], pre2[N][N];
set< ll > el;
map< ll, ll > idx;
set< vector< int > > st;

ll MOD(ll x){
    return ((x % mod + mod) % mod) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            scanf("%d", &a[i][j]);
            // el.insert(a[i][j]);
        }
    }

    // ll id = 1LL;

    // for(set< ll >::iterator it = el.begin() ; it != el.end() ; it++){
    //     idx[*it] = id;
    //     id++;
    // }

    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1 ; j <= m ; j++){
    //         a[i][j] = idx[a[i][j]];
    //     }
    // }

    // for(int i = 1 ; i <= n ; i++){
    //     ll c1 = PRIME1, c2 = PRIME2;

    //     for(int j = 1 ; j <= m ; j++){
    //         pre1[i][j] = c1 * a[i][j];

    //         pre1[i][j] += pre1[i][j - 1];
    //         pre1[i][j] = MOD(pre1[i][j]);

    //         c1 *= PRIME1;
    //         c1 = MOD(c1);
    //         // pre2[i][j] = c1 * a[i][j];

    //         // pre2[i][j] += pre2[i][j - 1];
    //         // pre2[i][j] = MOD(pre2[i][j]);

    //         // c2 *= PRIME2;
    //         // c2 = MOD(c2);
    //     }
    // }

    ll tot = 0LL;

    for(int i = 1 ; i <= m ; i++){
        for(int j = i ; j <= m ; j++){
            for(int ki = 1 ; ki <= n ; ki++){
                for(int kj = ki ; kj <= n ; kj++){
                    vector< int > nw;

                    for(int t = i ; t <= j ;t++){
                        nw.push_back(a[kj][t]);
                    }

                    st.insert(nw);

                    tot += ll(st.size());
                }
                
                st.clear();
            }
        }
    }

    printf("%lld\n", tot);

    return 0;
}