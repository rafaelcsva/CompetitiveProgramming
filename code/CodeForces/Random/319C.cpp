#include <bits/stdc++.h>

using namespace std;

struct line {
	long long m, c;
	long long eval(long long x) { return m * x + c; }
	long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};

const int N = int(2e5);
typedef long long	ll;
ll a[N], b[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		scanf("%lld", &a[i]);
		// a[i] *= -1;
	}

	for(int i = 1 ; i <= n ; i++){
		scanf("%lld", &b[i]);
	}

	deque<line> dq;
	dq.push_front({b[1], 0LL});//caso base
	
	ll ans = b[1];

	for (int i = 2; i <= n; i++) {

		while (dq.size() >= 2 && dq.back().eval(a[i]) > dq[dq.size() - 2].eval(a[i])) //Inverta caso queira o máximo
			dq.pop_back();

		ll f = dq.back().eval(a[i]);
		
		if(i == n){
			ans = f;
		}

		line cur = {b[i], f};
		while (dq.size() >= 2 && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1]))
			dq.pop_front();
		dq.push_front(cur);
	}

	printf("%lld\n", ans);

	return 0;
}