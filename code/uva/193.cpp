#include <bits/stdc++.h>

using namespace std;

const int N = 110, inf = (int) 1e6;
int graph[N][N];
int n, k, t;
int ans = 0;

set<int>::iterator it, mn;
bitset<N>st(N), resp;

void backtracking(int i, int act){
	if(i == n){
		if(ans < act){
			ans = act;
			
			resp = st;
		}
	}else{
		bool canInsert = true;
		
		for(int k = 0 ; k < i ; k++){
			if(st[k] == 1){
				if(graph[k][i] == t){
					canInsert = false;
					break;
				}
			}
		}
		
		if(canInsert){
			st[i] = 1;
			backtracking(i + 1, act + 1);
		}
		
		st[i] = 0;
		
		backtracking(i + 1, act);
	}
}

int main (){
	int m;
	
	scanf("%d", &m);
	
	for(t = 1 ; t <= m ; t++){
		scanf("%d%d", &n, &k);
		
		while(k--){
			int a, b;
			
			scanf("%d%d", &a, &b);
			
			a--;
			b--;
			
			graph[a][b] = t;
			graph[b][a] = t;
		}
		
		backtracking(0, 0);
		
		printf("%d\n", ans);
		
		for(int i = 0 ; i < n ; i++){
			char c = ans == 1 ? '\n' : ' ';
			
			if(resp[i] == 1){
				printf("%d%c", i + 1, c);
				ans--;
			}
			
			if(!ans)
				break;
		}
		
	}

	return 0;
}
