#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e3;
pair<int, int>pii[N];
int reach;
int n;

void dfs(int k){
	reach++;
	int x = pii[k].first, y = pii[k].second;
	
	pii[k].first = -1;
	
	for(int i = 0 ; i < n ; i++){
		if(pii[i].first == -1){
			continue;
		}
		
		if(pii[i].first == x || pii[i].second == y){
			dfs(i);
		}
		
	}
	
}
int main (){
	
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &pii[i].first, &pii[i].second);
	}
	
	int comp = 0;
	
	while(reach < n){
		int x = 0;
		
		comp++;
		
		for(int i = 0 ; i < n ; i++){
			if(pii[i].first != -1){
				x = i;
			}
		}
		
		dfs(x);
	}
	
	printf("%d\n", comp - 1);
	
	return 0;
}
