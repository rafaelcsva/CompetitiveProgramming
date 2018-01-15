#include <bits/stdc++.h>

using namespace std;

const int N = 10, inf = (int) 1e9;
int v[N][N];
int ans = inf;
bitset<N>columns(0);
int n;
		
void backtracking(int l, int s1, int s2){
	if(l == n){
		ans = min(ans, s1 - s2);
	}else{
		for(int i = 0 ; i < n ; i++){
			if(columns[i] == 0){
				columns[i] = 1;
				
				int sa = 0, sb = 0;
				
				if(v[l][i] < 0){
					sb += -v[l][i];
				}else{
					sa += v[l][i];
				}
				
				columns[i] = 1;
				
				backtracking(l + 1, s1 + sa, s2 + sb);
				
				columns[i] = 0;
			}
		}	
	}
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				scanf("%d", &v[i][j]);
			}
		}
		
		backtracking(0, 0, 0);
		
		printf("%d\n", ans);
		
		ans = inf;
		columns.reset();
	}
	
	return 0;
}
