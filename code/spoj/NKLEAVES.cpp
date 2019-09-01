#include <bits/stdc++.h>

using namespace std;

struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};

const int N = int(1e5 + 100);
const int K = 20;
typedef long long    ll;
ll x[N], w[N];
ll dp[N][K];
ll pref[N], g[N];

int main(){
    int n, k;

    while(scanf("%d %d", &n, &k) != EOF){
	    for(int i = 1 ; i <= n ; i++){
	        scanf("%lld", &w[i]);
	        x[i] = i;

	        // a[i] *= -1;
	    }

	    reverse(w + 1, w + 1 + n);

	    for(int i = 1 ; i <= n ; i++){
	    	pref[i] = pref[i - 1] + w[i];
	    	g[i] = w[i] * x[i] + g[i - 1];
	    }

	    for(int i = 1 ; i <= n ; i++){
	    	dp[i][1] = x[i] * pref[i] - g[i];
	    }

	    deque<line> dq;

	    for(int j = 2 ; j <= k ; j++){
		    dq.push_front({0LL, 0LL});

		    for (int i = 1; i <= n; i++) {
		        while (dq.size() >= 2 && dq.back().eval(x[i]) > dq[dq.size() - 2].eval(x[i])){ //Inverta caso queira o maximo
		            dq.pop_back();
	        	}

		        ll f = dq.back().eval(x[i]);
		        dp[i][j] = x[i] * pref[i] - g[i] + f;
		        line cur = {-pref[i], dp[i][j - 1] + g[i]};

		        while (dq.size() >= 2 && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1]))
		            dq.pop_front();

		        dq.push_front(cur);
		    }

		    dq.clear();
		}

	    printf("%lld\n", dp[n][k]);
   	}

    return 0;
}
