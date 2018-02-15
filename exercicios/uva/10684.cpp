#include <bits/stdc++.h>

using namespace std;

int v[10010];

int main (){
	int n;
	
	while(scanf("%d", &n) && n){
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}
		
		int ans = v[0], tmp = v[0];
		
		for(int i = 1 ; i < n ; i++){
			tmp = max(v[i], v[i] + tmp);
			ans = max(ans, tmp);
		}
		
		if(ans > 0){
			printf("The maximum winning streak is %d.\n", ans);
		}else{
			printf("Losing streak.\n");
		}
	}
	
	return 0;
}
