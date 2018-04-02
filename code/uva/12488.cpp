#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int p[N], ac[N];

int main (){
	int n;
	
	while(scanf("%d", &n) != EOF){
		for(int i = 1 ; i <= n ; i++){
			int c;
			
			scanf("%d", &c);
			
			p[c] = i;
		}
		
		int ans = 0;
		
		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &ac[i]);
			
			for(int j = 1 ; j < i ; j++){
				if(p[ac[j]] > p[ac[i]]){
					ans++;
				}
			}
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
