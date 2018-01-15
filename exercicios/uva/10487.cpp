#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int v[N];

int main (){
	int n;
	int tst = 1;
	
	while(scanf("%d", &n) && n){
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}
		
		printf("Case %d:\n", tst++);
		
		int m;
		
		scanf("%d", &m);
		
		int ans = (int) 1e9;
		
		for(int i = 0 ; i < m ; i++){
			int c;
			
			scanf("%d", &c);
			
			for(int i = 0 ; i < n ; i++){
				for(int j = i + 1 ; j < n ; j++){
					int x = v[i] + v[j];
					
					if(abs(c - ans) > abs(c - x)){
						ans = x;
					}
				}
			}
			
			printf("Closest sum to %d is %d.\n", c, ans);
		}
	}

	return 0;
}
