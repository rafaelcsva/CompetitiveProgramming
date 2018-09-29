#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int father[N];
int a[N];
int qtd[N];

int find(int x){
	if(father[x] == x)
		return x;
		
	return father[x] = find(father[x]);
}

void join(int x, int y){
	int u = find(x);
	int v = find(y);

	if(u != v){
		if(u > v){
			father[u] = v;
			qtd[v] += qtd[u];
		}else{
			father[v] = u;
			qtd[u] += qtd[v];
		}
	}	
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n ; i++){
		father[i] = i;
		qtd[i] = 1;
	}
	
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			int g = __gcd(a[i], a[j]);
			
			if(g > 1){
				join(i, j);
			}
		}
	}	
	
	if(qtd[1] == n){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
		
	return 0;
}