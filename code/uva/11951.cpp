#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;

const int N = 110;
lli st[N][N], pre[N], arr[N], l;

int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		int n, m;
		
		scanf("%d%d%lld", &n, &m, &l);
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				scanf("%lld", &st[i][j]);
			}
		}
		
		int ans = 0;
		lli cost = 0LL;
		
		for(int i = 1 ; i <= n ; i++){
			for(int k = 1 ; k <= m ; k++){
				arr[k] = pre[k] = 0LL;
			}
			
			for(int j = i ; j <= n ; j++){
				for(int k = 1 ; k <= m ; k++){
					arr[k] += st[j][k];
				}
				
				for(int k = 1 ; k <= m ; k++){
					pre[k] = pre[k - 1] + arr[k];
				}
				
				int ini = 1;
				
				for(int k = 1 ; k <= m ; k++){
					lli cur = pre[k] - pre[ini - 1];
					
					if(cur > l){
						int ind = lower_bound(pre + ini, pre + k + 1, cur - l) - pre;
						
						ind++;
						
						ini = ind;
						
						if(ind == k + 1){
							continue;
						}else{
							cur = pre[k] - pre[ini - 1];
						}
					}
					
					int ar = (j - i + 1) * (k - ini + 1);
					
					if(ar > ans){
						cost = cur;
						
						ans = ar;
					}else if(ar == ans){
						cost = min(cost, cur);
					}
				}
			}
		}
		
		printf("Case #%d: %d %lld\n", test++, ans, cost);
	}

	return 0;
}
