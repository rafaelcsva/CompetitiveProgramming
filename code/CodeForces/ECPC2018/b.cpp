#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5 + 10);
long long a[N];
int n;

int main(){
	int t;

	freopen("task.in", "r", stdin);

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		long long mn = int(1e9 + 10);

		for(int i = 0 ; i < n ; i++){
			scanf("%lld", &a[i]);

			mn = min(mn, a[i]);
		}

		if(mn != 1){
			a[n++] = 1;
		}

		sort(a, a + n);

		long long best = n - 1;
		long long tmp = 0;

		if(mn != 1){
			best++;
			tmp = 1LL;
		}

		for(int i = 1 ; i < n ; i++){
			if(a[i] == a[i - 1]){
				tmp++;
			}else{
				tmp += a[i] - a[i - 1] - 1;
			}

			best = min(best, tmp + n - i - 1);
		}

		printf("%lld\n", best);
	}

	return 0;
}
