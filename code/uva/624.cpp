#include <bits/stdc++.h>

using namespace std;

const int N = 21;
int n;
int v[N];

int main (){
	while(scanf("%d", &n) != EOF){
		int m;
		
		scanf("%d", &m);
		
		for(int i = 0 ; i < m ; i++){
			scanf("%d", &v[i]);
		}
		
		int ans = 0;
		int resp = 0;
		
		for(int i = 1 ; i < 1 << m ; i++){
			int tmp = 0;
			
			for(int j = 0 ; j < m ; j++){
				
				if(i & (1 << j)){
					tmp += v[j];	
				}
				
			}
			if(tmp <= n){
				if(n - tmp < n - ans){
					ans = tmp;
					resp = i;
				}
			}
		}
		
		bitset<N>el(resp);
		
		for(int i = 0 ; i < N ; i++){
			if(el[i] == 1){
				printf("%d ", v[i]);
			}
		}
		
		printf("sum:%d\n", ans);
	}

	return 0;
}
