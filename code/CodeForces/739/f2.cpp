#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int D = 11;
const int M = (1024) + 10;

ll dp[D][M][2];
int used[D][M][2];

ll pt[D];
const ll inf = ll(1e18);
int test;

vector< int > get_num(long long x){
    vector< int > ans;

    while(x){
        ans.push_back(x % 10);
        x /= 10;
    }

    return ans;
}

ll solve(int i, int msk, bool frag, vector< int > &num, int &k){
    if(__builtin_popcount(msk) > k){
        return inf;
    }

    if(i < 0){
        return 0;
    }

    int &us = used[i][msk][frag];
    auto &ans = dp[i][msk][frag];

    if(us == test){
        return ans;
    }

    us = test;

    ans = inf;

    for(int d = 0 ; d < 10 ; d++){
        int e = 1 << d;

        if(frag || d >= num[i]){
            ans = min(ans, pt[i] * ll(d) + solve(i - 1, msk | e, frag | (d > num[i]), num, k));
            if(ans < inf){
                break;
            }
        }
    }

    return ans;
}

int main(){
    int t;

    pt[0] = 1LL;
    for(int i = 1 ; i < D ; i++){
        pt[i] = 10LL * pt[i - 1];
    }

    scanf("%d", &t);

    for(test = 1 ; test <= t ; test++){
        int n, k;

        scanf("%d %d", &n, &k);

        auto u = get_num(n);

        printf("%lld\n", solve(int(u.size()) - 1, 0, false, u, k));
    }

    return 0;
}
