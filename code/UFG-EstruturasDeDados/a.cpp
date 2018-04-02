#include <bits/stdc++.h>

#define	MAXIMO	999999
using namespace std;

typedef struct Arvore{
	int flag;
	int SomaTotal;
	int SomaEsq;
	int SomaDir;
	int SomaMax;	
}Arvore;

Arvore arvores[MAXIMO];

Arvore join(Arvore a, Arvore b){
	Arvore res ;

	res.SomaTotal = a.SomaTotal + b.SomaTotal ;

	res.SomaMax = max( max( a.SomaMax , b.SomaMax ) , (a.SomaDir + b.SomaEsq ) ) ;

	res.SomaEsq = max( a.SomaEsq , a.SomaTotal + b.SomaEsq );

	res.SomaDir = max( b.SomaDir , b.SomaTotal + a.SomaDir );

	return res ;
}

void ConstroiArvore(int no, int i, int j, int v[]){
	
	if(i == j){
		arvores[no].SomaTotal = arvores[no].SomaEsq = arvores[no].SomaDir = arvores[no].SomaMax = v[i];
		arvores[no].flag = 0;
	}else{
		int esq = no<<1;
		int dir = no<<1|1;

		ConstroiArvore(esq, i, (i+j)/2, v);
		ConstroiArvore(dir, (i+j)/2 + 1, j, v);

		//printf("(%d,%d) (%d,%d)+(%d,%d) (%d) (%d)\n", i, j, i, (i+j)/2, (i+j)/2+1, j, arvores[esq].SomaDir, arvores[dir].SomaDir);
		arvores[no] = join(arvores[esq], arvores[dir]);
		arvores[no].flag = 0;
	}
}

Arvore Consulta(int no, int i, int j, int x, int y){

	if(i >= x && j <= y){
	//	printf("%d %d\n", i, j);
		
		return arvores[no];	
	}else{
		int esq = no<<1;
		int dir = no<<1|1;
		
		int mid = (i+j)/2;

		if(mid >= y)
			return Consulta(esq, i, mid, x, y);
		else if(mid < x)
			return Consulta(dir, mid + 1, j, x, y);

		return join(Consulta(esq, i, mid, x, y), Consulta(dir, mid + 1, j, x, y));
	}
}

int main (){
	int n, m;
	int v[MAXIMO];

	scanf("%d", &n);
	
	for(int i = 1; i <= n ; i++)
		scanf("%d", &v[i]);

	ConstroiArvore(1, 1, n, v);
	scanf("%d", &m);

	for(int i = 0 ; i < m ; i++){
		int x, y;

		scanf("%d%d", &x, &y);

		printf("%d\n", Consulta(1, 1, n, x, y).SomaMax); 
	}		

	return 0;
}
