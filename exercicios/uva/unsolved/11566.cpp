#include <bits/stdc++.h>

using namespace std;

const int K = 110, N = 20;
int n, x, t, k;
int price[K], ind[K][N];
int f[K], q;

double solve(int f, int m, int i, int c){
	if(f == n + 1){
		
	}
}

int main (){
	while(scanf("%d%d%d%d", &n, &x, &t, &k)){
		if(n == 0)
			break;
			
		q++;
		
		for(int i = 0 ; i < k ; i++){
			scanf("%d", &price[i]);
			
			f[i] = 0;
			
			for(int j = 0; j <= n ; j++){
				scanf("%d", &price[i][j]);
				
				f[i] = max(f[i], price[i][j]);
			}
		}
		
		
	}
	
	return 0;
}
