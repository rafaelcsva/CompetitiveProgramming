#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int v[N];

int main (){
	int n;
	bool ver = false;	
	while(scanf("%d", &n) && n){
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}
		if(ver){
			printf("\n");
		}
		ver = true;
		for(int i = 0 ; i <= n - 6 ; i++){
			for(int j = i + 1 ; j <= n - 5 ; j++){
				for(int m = j + 1 ; m <= n - 4 ; m++){
					for(int y = m + 1 ; y <= n - 3 ; y++){
						for(int x = y + 1 ; x <= n - 2 ; x++){
							for(int h = x + 1 ; h <= n - 1 ; h++){
								printf("%d %d %d %d %d %d\n", v[i], v[j], v[m], v[y], v[x], v[h]);
							}
						}
					}
				}
			}
		} 

	}

	return 0;
}
