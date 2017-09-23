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
	int n, m, t;
	int v[MAXIMO];
 
	scanf("%d", &t);	
 
	for(int i = 0 ; i < t; i++){
		scanf("%d", &n);
 
		for(int k = 1 ; k <= n ; k++)
			scanf("%d", &v[k]);
 
		ConstroiArvore(1, 1, n, v);
 
		scanf("%d", &m);
 
		for(int k = 0; k < m ; k++){
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			
			int r;
 
			if(x2 >= y1){
				int a = Consulta(1, 1, n, x1, y1).SomaDir;
 
				int b = Consulta(1, 1, n, y1, x2).SomaTotal;
 
				int c =  Consulta(1, 1, n, x2, y2).SomaEsq ;
	
				r = a+b+c-v[y1] - v[x2];
 
			}else{
				Arvore a = Consulta(1, 1, n, x1, x2);
				Arvore b = Consulta(1, 1, n, x2, y1);
				Arvore c = Consulta(1, 1, n, y1, y2);
 
				r = max(c.SomaEsq, max(a.SomaDir , max(a.SomaDir+b.SomaTotal+c.SomaEsq-v[x2]-v[y1] , max(b.SomaMax , a.SomaDir+b.SomaEsq-v[x2]))));
			
				a = Consulta(1, 1, n, x1, y1);
			
				r = max(r, a.SomaDir + c.SomaEsq - v[y1]);
			}
 
 			//x1 y1 x2 y2
 			
 			//x1 x2 y1 y2
 			
 			
			printf("%d\n", r);
 
		}
	}
 
	return 0;
}
