#include <bits/stdc++.h>
#include <functional> 

using namespace std;

typedef long long int	lli;

const int N = (int) 1e4;
priority_queue<lli, vector<lli> , greater<lli> > pq;

int main (){
	int n;

	while(scanf("%d", &n)){
		if(n == 0)
			break;

		lli v;

		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &v);

			pq.push(v);
		}

		lli ans = 0;

		while(pq.size() != 1){
			lli a = pq.top();
			pq.pop();

			lli b = pq.top();
			pq.pop();

			pq.push(a + b);

			ans += a + b;
		}

		printf("%lld\n", ans);
		pq.pop();
	}

	return 0;
}
