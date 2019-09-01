#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;

priority_queue< pii > pq;

const int N = int(1e5 + 10);
int ans[N];
int h[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		int hi;

		scanf("%d", &hi);
		h[i] = hi;

		while(!pq.empty()){
			if(-pq.top().first >= hi){
				break;
			}

			pii u = pq.top();
			pq.pop();

			ans[u.second] = i - u.second - 1;
		}

		pq.push({-hi, i});
	}

	while(!pq.empty()){
		ans[pq.top().second] = n - pq.top().second;
		pq.pop();
	}

	for(int i = 1 ; i <= n ; i++){
		ans[i] = min(ans[i], h[i]);
		printf("%d ", ans[i]);
	}

	printf("\n");

	return 0;
}