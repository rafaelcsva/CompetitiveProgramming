#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int arr[N], sq[N][N];

int main (){
	int n, t;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
	
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				scanf("%d", &sq[i][j]);
				
				sq[i][j + n] = sq[i][j];
				sq[i + n][j] = sq[i][j];
				sq[i + n][j + n] = sq[i][j];
			}
		}
		
		int m = 2 * n;
		
		int ans = -101;
		
		for(int i = 1 ; i <= n ; i++){
			for(int k = 1 ; k <= m ; k++){
				arr[k] = 0;
			}
			
			for(int j = i, t = 1 ; j <= m && t <= n ; j++, t++){
				for(int k = 1 ; k <= m ; k++){
					arr[k] += sq[j][k];
				}
				
				for(int k = 1 ; k <= m ; k++){
					int tmp = 0;
					
					for(int l = k, c = 1 ; l <= m && c <= n ; l++, c++){
						tmp = max(tmp, 0) + arr[l];
						
						ans = max(ans, tmp);
					}
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
