#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 14;
ll a[N];
vector< int > submask[1 << N];
vector< ll > g[1 << N];
int acc[1 << N];
int fnd[1 << N];

bool compar(int a, int b){
    return __builtin_popcount(a) < __builtin_popcount(b);
}

ll prob(int msk, int u){
    ll ans = 1LL;

    u = acc[u];

    while(msk){
        int a = msk & (msk - 1);
        msk -= a;

        a = acc[a];

        ans *= calc(a, u);
        ans %= mod;
    }

    return ans;
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%lld", &a[i]);
        acc[1 << i] = i;
    }

    for(int e = 0 ; e < (1 << n) ; e++){
        for(int s = e ; s ; s = (s - 1) & e){
            submask[e].push_back(s);
        }

        submask[e].push_back(0);
        sort(submask[e].begin(), submask[e].end(), compar);
        g[e].resize(submask[e].size());

        for(int i = 0 ; i < submask[e].size() ; i++){
            int msk = submask[e][i];
            fnd[msk] = i;

            int u = msk & (msk - 1);

            if(i == 0){
                g[e][i] = 1;
            }else{
                msk ^= u;

                int idx = fnd[msk];

                g[e][i] = (prob(msk, u) * g[e][idx]) % mod;
            }
        }
    }

    return 0;
}