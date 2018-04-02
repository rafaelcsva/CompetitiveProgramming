#include <bits/stdc++.h>

using namespace std;

const int K = 10;
const int N = 1000010;
int g[N], pre[K][N];

int prod(int x){
	int prod = 1;
	
	while(x){
		
		if(x % 10 != 0)
			prod = prod * (x % 10);
			
		x /= 10;
	}
	
	return prod;
}

int calc(int x){
	if(x < 10){
		return x;
	}
	
	if(g[x] != -1){
		return g[x];
	}
	
	return g[prod(x)];
}


void precalc(){
	for(int i = 0 ; i < N ; i++){
		g[i] = calc(i);
	}
}

int main (){
	for(int i = 0 ; i < N ; i++){
		g[i] = -1;
	}
	
	precalc();

	for(int t = 1 ; t < K ; t++){
		for(int i = 1 ; i < N ; i++){
			pre[t][i] = g[i] == t;
		}	
	}

	for(int t = 1 ; t < K ; t++){
		for(int i = 1 ; i < N ; i++){
			pre[t][i] += pre[t][i - 1];
		}
	}
	
	int q;
	
	scanf("%d", &q);
	
	while(q--){
		int l, r, k;
		
		scanf("%d%d%d", &l, &r, &k);
		
		printf("%d\n", pre[k][r] - pre[k][l - 1]);
	}
	
	return 0;
}
