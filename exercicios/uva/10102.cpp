#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;
char tab[1000][1000];

int main (){
	int n;
	
	while(scanf("%d", &n) != EOF){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				
				scanf("\n%c", &tab[i][j]);
			}
		}
		
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(tab[i][j] == '1'){
					int tmp = inf;
					
					for(int m = 0 ; m < n ; m++){
						for(int k = 0 ; k < n ;k++){
							if(tab[m][k] == '3'){
								tmp = min(tmp, abs(i - m) + abs(k - j));
							}
						}
					}
					
					ans = max(ans, tmp);
				}
			}
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
