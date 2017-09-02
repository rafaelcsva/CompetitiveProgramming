#include <bits/stdc++.h>

#define MAXIMO	100100

using namespace std;

int pai[MAXIMO];

int query(int x){
	if(pai[x] == x)
		return x;

	return pai[x] = query(pai[x]);
}

int join(int a, int b){
	int m = query(a);
	int n = query(b);

	if(m!=n){
		if(m > n){
			pai[m] = n;
		}
		else{
			pai[n] = m;
		}
	}
}

int main (){
	int n, k;

	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n ; i++)
		pai[i] = i;

	for(int i = 0 ; i < k ; i++){
		char op;
		int a, b;

		scanf("\n%c", &op);
		scanf("%d%d", &a, &b);

		if(op == 'C'){
			int m = query(a);
			int n = query(b);

			if(m == n)
				printf("S\n");
			else
				printf("N\n");
		}else{
			join(a,b);
		}
	}

	return 0;	 	
}
