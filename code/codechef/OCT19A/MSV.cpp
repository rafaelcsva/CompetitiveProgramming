#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6 + 10);
int cnt[N];
int a[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);
			
		int ans = 0;

		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &a[i]);

			ans = max(ans, cnt[a[i]]);

			for(int j = 1 ; j * j <= a[i] ; j++){
				if(a[i] % j == 0){
					cnt[j]++;

					if(j * j != a[i]){
						cnt[a[i] / j]++;
					}
				}
			}
		}

		printf("%d\n", ans);

		memset(cnt, 0, sizeof cnt);
	}

	return 0;
}