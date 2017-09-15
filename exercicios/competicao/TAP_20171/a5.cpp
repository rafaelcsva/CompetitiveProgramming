#include <bits/stdc++.h>

#define	MAXIMO	100010

using namespace std;

typedef struct Arvore{
	int notas[10];
}Arvore;

Arvore arvores[MAXIMO<<3];
int lazy[MAXIMO<<3];

Arvore Nova(){
	Arvore r;

	for(int k = 0 ; k < 9 ; k++)
		r.notas[k] = 0;

	r.notas[1] = 1;

	return r;
}

Arvore join(Arvore a, Arvore b){
	Arvore r;

	for(int i = 0 ; i < 9 ; i++){
	//	printf("%d %d %d\n",i ,a.notas[i], b.notas[i]);
		r.notas[i] = a.notas[i] + b.notas[i];
	}

	return r;
}

void Build(int no, int i, int j){
	if(i == j){
		arvores[no] = Nova();
	}else{
		int esq = no<<1;
		int dir = no<<1|1;

		Build(esq, i, (i+j)/2);
		Build(dir, (i+j)/2 + 1, j);
	
		//printf("%d %d\n", i, j);
		arvores[no] = join(arvores[esq], arvores[dir]);
	}
}

void next(int no, int p){
	int l = (lazy[no] + p)%9;
	//printf("next\n");

	if(l > 0){
		int aux[10];

		for(int i = 0 ; i < 9 ; i++){
			aux[i] = arvores[no].notas[i];
		}

		for(int i = 0 ; i < 9 ; i++){
			arvores[no].notas[(i+l)%9] = aux[i]; 
		}
	}
	
}

Arvore Query(int no, int i, int j, int x, int y){
	int esq = no<<1;
	int dir = no<<1|1;
	
	if(lazy[no]){
		int p = lazy[no];
		next(no, 0);

		if(i != j){
			lazy[esq] += p;
			lazy[dir] += p;
		}
	}

	if(i >= x && j <= y){
		return arvores[no];
	}else{
		int mid = (i+j)/2;

		if(mid >= y){
			return Query(esq, i, mid, x, y);
		}
	
		if(mid < x){
			return Query(dir, mid+1, j, x, y);
		}
			
		return join(Query(esq, i, mid, x, y), Query(dir, mid+1, j, x, y)); 
	}
}

int maisFrequente(Arvore n){
	int maior = -1;
	int f;

	for(int i = 8 ; i >= 0 ; i--){
	//	printf("%d > %d (%d)\n", n.notas[i], maior, i);
		if(n.notas[i] > maior){
			f = i;
			maior = n.notas[i];
		}
	}

	return f;
}

void Update(int no, int i, int j, int x, int y){
	int esq = no<<1;
	int dir = no<<1|1;

	if(lazy[no]){
		int p = lazy[no];

		next(no, 0);

		if(i != j){
			lazy[esq] += p;
			lazy[dir] += p;
		}
	}

	if(i > y || j < x)
		return;

	if(i >= x && j <= y){
		int f = maisFrequente(arvores[no]);

		next(no, f);

		if(i != j){
			lazy[esq] += f;
			lazy[dir] += f;
		}
	}else{
		int mid = (i+j)/2;

		Update(esq, i, mid, x, y);

		Update(dir, mid + 1, j, x, y);

		arvores[no] = join(arvores[esq], arvores[dir]);
	}
}

int main (){
	int n, q;

	scanf("%d%d", &n, &q);
	
	Build(1, 1, n);
//	printf("builded\n");
	for(int i = 0 ; i < q; i++){
		int a, b;

		scanf("%d%d", &a, &b);

		printf("mais frequente %d %d %d\n", maisFrequente(Query(1, 1, n, a+1, b+1)), a+1, b+1);
		
		Update(1, 1, n, a+1, b+1);

		printf("mais frequente %d %d %d\n", maisFrequente(Query(1, 1, n, a+1, b+1)), a+1, b+1);
	}

	for(int i = 1; i <= n ; i++)
		printf("%d\n", maisFrequente(Query(1, 1, n, i, i)));

	return 0;
}
