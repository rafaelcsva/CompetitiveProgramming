#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int v[N];
int pos[N];

int main (){
	int n;
	
	while(scanf("%d:", &n)){
		if(n == 0){
			break;
		}
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
			pos[v[i]] = i;
		}
		
		bool ver = true;
		
		for(int i = 0 ; i < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				int r = v[j] - v[i];
				int x = v[j] + r;
				
				if(x >= 0 && x < n){
					if(pos[x] > j){
						ver = false;
						break;
					}
				}
			}
			
			if(!ver)
				break;
		}
		
		if(ver){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	
	return 0;
}
