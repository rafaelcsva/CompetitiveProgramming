#include <bits/stdc++.h>

using namespace std;

const int N = 501, M = 501;
int v[N][M], v1[N][M];

int main (){
	int n, m;
	
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				scanf("%d", &v[i][j]);
			}
		}
		
		int q;
		
		scanf("%d", &q);
		
		while(q--){
			int l, r;
			
			scanf("%d %d", &l, &r);
			
			int ans = 0;
			
			for(int i = 0 ; i < n ; i++){
				int t = lower_bound(v[i], v[i] + m, l) - v[i];
				
				for(int j = ans ; j < n ; j++){
					if(j + i >= n || j + t >= m || v[j + i][j + t] > r)
						break;
						
					ans = j + 1;
				}
			}
			
			printf("%d\n", ans);
		}
		printf("-\n");
	}

	return 0;
}
