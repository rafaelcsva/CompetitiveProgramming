#include <bits/stdc++.h>

using namespace std;

int f[5100];

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &f[i]);
	}

	for(int i = 1 ; i <= n ; i++){
		int j = 0;
		int ti = f[i];
		
		while(j < 2){
			ti = f[ti];
			j++;
		}
		
		if(ti == i){
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");
	return 0;
}
