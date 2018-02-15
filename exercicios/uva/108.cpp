#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int sq[N][N];
int arr[N];

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%d", &sq[i][j]);
		}
	}	
	
	int ans = -128;
	
	for(int i = 1; i <= n ; i++){
		for(int k = 1 ; k <= n ; k++){
			arr[k] = 0;
		}
			
		for(int j = i ; j <= n ; j++){
			for(int k = 1 ; k <= n ; k++){
				arr[k] += sq[j][k];
			} 
			
			int tmp = 0;
			
			for(int k = 1 ; k <= n ; k++){
				tmp = max(tmp, 0) + arr[k];
			
				ans = max(ans, tmp);
			}
		}
	}
	
	printf("%d\n", ans);
	 
	return 0;
}
