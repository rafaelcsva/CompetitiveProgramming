#include <bits/stdc++.h>

#define	MAXIMO	100010

using namespace std;

typedef struct Arvore{
	int n0, n1, n2;
}Arvore;

Arvore arvores[MAXIMO<<3];
int lazy[MAXIMO<<3];

void Build(int no, int i, int j){
	if(i == j){
		arvores[no].n0 = 1;
		arvores[no].n1 = arvores[no].n2 = 0;
	}else{
		int esq = no<<1;
		int dir = no<<1|1;

		Build(esq, i, (i+j)/2);
		Build(dir, (i+j)/2 + 1, j);

		arvores[no].n0 = arvores[esq].n0 + arvores[dir].n0;
		arvores[no].n1 = arvores[no].n2 = 0;
	}
}

Arvore join(Arvore a, Arvore b){
	Arvore r;

	r.n0 = a.n0 + b.n0;
	r.n1 = a.n1 + b.n1;
	r.n2 = a.n2 + b.n2;
	
	return r;
}

void next(int no, int p){
	int l = (lazy[no] + p)%3;

	lazy[no] = 0;
	
	switch(l){
		case 1:	swap(arvores[no].n0, arvores[no].n1);
			swap(arvores[no].n0, arvores[no].n2);
			break;

		case 2:	swap(arvores[no].n0, arvores[no].n2);
			swap(arvores[no].n0, arvores[no].n1); 
	}
}

Arvore Query(int no, int i, int j, int x, int y){
	if(lazy[no]){
		next(no, 0);
	}

	if(i >= x && j <= y){
		return arvores[no];
	}else{
		int esq = no<<1;
		int dir = no<<1|1;
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
		next(no, 1);

		if(i != j){
			lazy[esq] += 1;
			lazy[dir] += 1;
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
	for(int i = 0 ; i < q; i++){
		int op, a, b;

		scanf("%d%d%d", &op, &a, &b);

		if(op == 0){
			Update(1, 1, n, a+1, b+1);
		}
		else if(op == 1){
			printf("%d\n", Query(1, 1, n, a+1, b+1).n0);
		}
	}

	return 0;
}
