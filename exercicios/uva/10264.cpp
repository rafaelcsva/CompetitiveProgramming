#include <bits/stdc++.h>

#define lli	long long int
using namespace std;

const int N = 1 << 15;
lli sum[N];

int main (){
	int n;
	int a[N];
	bool flag = false;

	while(scanf("%d", &n) != EOF){
		int corner = 1 << n;

		for(int i = 0 ; i < corner ; i++){
			scanf("%d", &a[i]);
		}

		for(int i = 0 ; i < corner ; i++){
			for(int j = 0 ; j < n ; j++){
				int neigh = i ^ (1 << j);
	
				sum[i] += a[neigh];
			}
		}

		lli ans = 0;

		for(int i = 0 ; i < corner ; i++){

			for(int j = 0 ; j < n ; j++){
				int neigh = i ^ (1 << j);
				
				ans = max(ans, sum[i] + sum[neigh]);
			}

			
		}

		printf("%lld\n", ans);

		for(int i = 0 ; i < corner ; i++)
			sum[i] = 0;
	}

	return 0;
}
