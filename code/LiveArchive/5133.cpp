#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

bool Q;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line &o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if(y == end()) { x->p = inf; return false; }
        if(x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m){
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(isect(y, z)) z = erase(z);
        if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x){
        assert(!empty());
        Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
        // printf("lk: %lld\n", l.k);
        return l.k * x + l.m;
    }
};

const int N = int(1e5) + 10;
ll dp[N];

struct Machine {
    ll d, p, r, g;
};

Machine m[N];

bool compar(Machine a, Machine b){
    return a.d < b.d;
}

int test = 1;

int main(){
    int n;
    ll C, D;

    while(true){
        scanf("%d %lld %lld", &n, &C, &D);

        if(n == 0){
            break;
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%lld %lld %lld %lld", &m[i].d, &m[i].p, &m[i].r, &m[i].g);
        }

        sort(m, m + n, compar);

        LineContainer luisfabiano;
        luisfabiano.add(0LL, C);

        for(int i = 0 ; i < n ; i++){
            ll x = luisfabiano.query(m[i].d - 1);
        
            if(x < m[i].p){
                continue;
            }

            dp[i] = x + m[i].r - m[i].d * m[i].g - m[i].p;
            // printf("%lld %lld %lld\n", m[i].d, dp[i], x);
            luisfabiano.add(m[i].g, dp[i]);
        }

        ll ans = luisfabiano.query(D);

        printf("Case %d: %lld\n", test++, ans);
    }

    return 0;
}
