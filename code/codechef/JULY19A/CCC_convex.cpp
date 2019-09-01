#include <bits/stdc++.h>

using namespace std;


const int N = 1010;
const int K = 1010;
typedef long long    ll;
ll x[N], w[N];
ll dp[N][K];
ll pref[N], g[N];
const ll inf = ll(1e9 + 10);

bool Q;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.k * x + l.m;
    }
};

int main(){
    int n, k;
    int t;

    scanf("%d", &t);

    while(t--){
    	scanf("%d %d", &n, &k);

	    for(int i = 1 ; i <= n ; i++){
	        scanf("%lld", &w[i]);
	    }

	    sort(w + 1, w + 1 + n);

	    for(int j = 1 ; j <= k ; j++){
	    	LineContainer con;

		    for (int i = j; i <= n; i++) {
	        	dp[i][j] = dp[i - 1][j - 1] + w[i];

	        	if(con.size()){
			        ll f = -con.query(i);
			        
			        dp[i][j] = min(f, dp[i][j]);
			        // printf("f: %lld (%d, %d)\n", f, i, j);
		        }
		        // Line cur = {-w[i], -(dp[i][j] - w[i] * ll(i))};
		        // printf("inserting (%lld, %lld %lld)\n", w[i], dp[i][j] - w[i] * ll(i), dp[i][j]);

		        con.add(-w[i], -(dp[i][j] - w[i] * ll(i)));
		    }

		}

	    printf("%lld\n", dp[n][k]);
   	}

    return 0;
}
