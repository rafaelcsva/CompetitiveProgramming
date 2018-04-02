#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
const int N = 23;
const lli inf = (lli) 10e9;
lli sum[N][N][N];

int n, m, k;

lli rangeSum(int i, int j, int l, int r){
	lli tmp = 0LL;
	lli ans = -inf;
	
	for(int t = 1 ; t <= n ; t++){
		if(tmp < 0LL){
			tmp = 0LL;
		}
		
		for(int g = i; g <= l ; g++){
			tmp += sum[t][g][r] - sum[t][g][j - 1];
		}
		
		ans = max(ans, tmp);
	}
	
	return ans;
}

int main (){
	int t;
	bool ver = false;
	
	scanf("%d", &t);
	
	while(t--){
		if(ver){
			printf("\n");
		}
		
		ver = true;
		
		scanf("%d%d%d", &n, &m, &k);
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				for(int d = 1 ; d <= k ; d++){
					scanf("%lld", &sum[i][j][d]);
					
					sum[i][j][d] += sum[i][j][d - 1];
				}
			}
		}
		
		lli ans = -inf;
		
		for(int i = 1 ; i <= m ; i++){
			for(int j = 1 ; j <= k ; j++){
				
				for(int l = i ; l <= m ; l++){
					for(int r = j ; r <= k ; r++){
						ans = max(ans, rangeSum(i, j, l, r));
						
					}
				}
			}	
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
