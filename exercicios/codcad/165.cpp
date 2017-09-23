#include <bits/stdc++.h>
#define INF	99999999
using namespace std;
#define MAXIMO	200010
 
typedef struct No {
	int size;
	int sum;
	int size_l;
	int sum_l;
	int size_r;
	int sum_r;
	int max_size;
	int max_sum;
}no;
 
No join (No a, No b){

	no aux;

	if (a.size == -1)
		return b;
	if (b.size == -1)
		return a;

	aux.size = a.size + b.size;
	aux.sum = a.sum + b.sum;

	aux.sum_l = -INF;
	aux.size_l = -INF;

	if (aux.sum_l < a.sum){
		aux.sum_l = a.sum;
		aux.size_l = a.size;
	}

	if (aux.sum_l < a.sum_l){
		aux.sum_l = a.sum_l;
		aux.size_l = a.size_l;
	}

	if (aux.sum_l < (a.sum+b.sum_l)){
		aux.sum_l = a.sum + b.sum_l;
		aux.size_l = a.size + b.size_l;
	}

	if (aux.sum_l == (a.sum+b.sum_l)){
		aux.size_l = max (aux.size_l, a.size+b.size_l);
	}

	if (aux.sum_l == a.sum_l){
		aux.size_l = max (aux.size_l, a.size_l);
	}

	if (aux.sum_l == a.sum){
		aux.size_l = max (aux.size_l, a.size);
	}

	aux.sum_r = -INF;
	aux.size_r = -INF;

	if (aux.sum_r < b.sum){
		aux.sum_r = b.sum;
		aux.size_r = b.size;
	}

	if (aux.sum_r < b.sum_r){
		aux.sum_r = b.sum_r;
		aux.size_r = b.size_r;
	}

	if (aux.sum_r < (b.sum+a.sum_r)){
		aux.sum_r = b.sum+a.sum_r;
		aux.size_r = b.size + a.size_r;
	}

	if (aux.sum_r == (b.sum+a.sum_r)){
		aux.size_r = max (aux.size_r, b.size+a.size_r);
	}

	if (aux.sum_r == b.sum_r){
		aux.size_r = max (aux.size_r, b.size_r);
	}

	if (aux.sum_r == b.sum){
		aux.size_r = max (aux.size_r, b.size);
	}

	aux.max_sum = -INF;
	aux.max_size = -INF;

	if (a.max_sum > aux.max_sum){
		aux.max_sum = a.max_sum;
		aux.max_size = a.max_size;
	}
	else if (a.max_sum == aux.max_sum){
		aux.max_size = max (aux.max_size, a.max_size);
	}

	if (b.max_sum > aux.max_sum){
		aux.max_sum = b.max_sum;
		aux.max_size = b.max_size;
	}
	else if (b.max_sum == aux.max_sum){
		aux.max_size = max (aux.max_size, b.max_size);
	}

	if (aux.max_sum < (b.sum+a.sum_r)){
		aux.max_sum = b.sum + a.sum_r;
		aux.max_size = b.size + a.size_r;
	}
	else if (aux.max_sum == (b.sum + a.sum_r)){
		aux.max_size = max (b.size+a.size_r, aux.max_size);
	}

	if (aux.max_sum < (a.sum + b.sum_l)){
		aux.max_sum = a.sum + b.sum_l;
		aux.max_size = a.size + b.size_l;
	}
	else if (aux.max_sum == (a.sum + b.sum_l)){
		aux.max_size = max (a.size+b.size_l, aux.max_size);
	}

	if (aux.max_sum < (a.sum_r + b.sum_l)){
		aux.max_sum = a.sum_r + b.sum_l;
		aux.max_size = a.size_r + b.size_l;
	}
	else if (aux.max_sum == (a.sum_r + b.sum_l)){
		aux.max_size = max (aux.max_size, (a.size_r + b.size_l));
	}

	if (aux.max_sum < aux.sum){
		aux.max_sum = aux.sum;
		aux.max_size = aux.size;
	}
	else if (aux.max_sum == aux.sum){
		aux.max_size = max (aux.max_size, aux.size);
	}

	return aux;
}

no segtree[300010];
int valores[MAXIMO];

void inicializa (int node, int l, int r){

	no aux;

	if (l > r) return;

	if (l == r){
		aux.size = 1;
		aux.size_l = 1;
		aux.size_r = 1;
		aux.max_size = 1;
		aux.sum = valores[r];
		aux.sum_l = valores[r];
		aux.sum_r = valores[r];
		aux.max_sum = valores[r];
		segtree[node] = aux;
	}
	else {
		inicializa (2*node, l, (l+r)/2);
		inicializa (2*node+1, (l+r)/2+1, r);

		segtree[node] = join (segtree[2*node], segtree[2*node+1]);
	}
}


 
no ConsultarArvore(int node, int i, int j, int ini, int fim){
	if(i > fim || j < ini || i > j){
		no r;
		r.size = -1;

		return r;
	}
 
	if(i >= ini && j <= fim){
	
		return segtree[node];
	}else{
 
		int esquerda = node*2;
		int direita = node*2 + 1;
 
		no vEsquerda = ConsultarArvore(esquerda, i, (i+j)/2, ini, fim);
		no vDireita = ConsultarArvore(direita, (i+j)/2+1, j, ini, fim);
 
		if(vEsquerda.size == -1){
			return vDireita;
		}

		if(vDireita.size == -1){
			return vEsquerda;	
		}
			
		return join(vDireita, vEsquerda);
	}
}
 
int main (){
	int t;
	int n;
	int q;
 
	scanf("%d", &t);
 
	while(t--){
 
		scanf("%d", &n);
 
		for(int i = 1 ; i <= n ; i++)
			scanf("%d", &valores[i]);
 
		inicializa(1, 1, n);
 
		int q;
 
		scanf("%d", &q);
 
		for(int i = 0 ; i < q ; i++){
			int a, b;
 
			scanf("%d%d", &a, &b);
 
			no r = ConsultarArvore(1,1,n,a,b);
 
			printf("%d %d\n", r.max_sum, r.max_size);

		}
	}
	
	return 0;
}
