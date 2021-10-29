#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 30;
const ll mod = 998244353LL;

ll pota[N];
vector< pair< ll, int > > con[1 << 10];

int main(){
    ll k, A, h;

    scanf("%lld %lld %lld", &k, &A, &h);

    pota[0] = 1LL;

    for(int i = 1 ; i < N ; i++){
        pota[i] = (A * pota[i - 1]) % mod;
    }

    int teams = 1 << k;
    int hf = teams >> 1;

    for(int m = 0 ; m < hf ; m++){
        auto v = get_teams(m, hf);
        auto sum = get_sum(m);
    }


    return 0;
}