#include <bits/stdc++.h>

#define MAXIMO	100100

using namespace std;

int pontuacao[MAXIMO];
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
		if(m>n){
			pontuacao[n] += pontuacao[m];
			pai[m] = n;
		}else{
			pontuacao[m] += pontuacao[n];
			pai[n] = m;
		}
	}
}

int main (){
	int n, m, vitorias;

	while(scanf("%d%d", &n, &m)&&n&&m){
		vitorias = 0;

		for(int i = 1 ; i <= n ; i ++){
			scanf("%d", &pontuacao[i]);
			pai[i] = i;
		}

		while(m--){
			int q, a, b;

			scanf("%d%d%d", &q, &a, &b);

			if(q == 1){
				join(a, b);
			}else{
				int m = query(a);
				int n = query(b);
				int gRafael = query(1);

				if(pontuacao[m] > pontuacao[n]){
					if(gRafael == m)
						vitorias++;
				}
				else if(pontuacao[n] > pontuacao[m]){
					if(gRafael == n)
						vitorias++;
				}
			}
		}

		printf("%d\n", vitorias);
	}

	return 0;
}
