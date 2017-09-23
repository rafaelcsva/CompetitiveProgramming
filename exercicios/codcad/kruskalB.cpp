#include <bits/stdc++.h>

#define	MAXIMO_VERTICES	510
#define MAXIMO_ARESTAS	129999

using namespace std;


typedef struct ArestaF{
	int u, v, w;
}ArestaF;

typedef struct ArestaR{
	int u, v, w;
}ArestaR;

int pai[MAXIMO_VERTICES];
ArestaR arestasR[MAXIMO_ARESTAS];
ArestaF arestasF[MAXIMO_ARESTAS];

int query(int x){
	if(pai[x] == x)
		return x;

	return pai[x] = query(pai[x]);
}

int join(int u, int v, int w){
	int x = query(u);
	int y = query(v);

	if(x!=y){
		if(x > y){
			pai[x] = y;
		}else{
			pai[y] = x;
		}

		return w;
	}

	return 0;
}

int compar1(const void *a, const void *b){
	int w1 = ((ArestaR *)a)->w;
	int w2 = ((ArestaR *)b)->w;

	return w1-w2;
}

int compar2(const void *a, const void *b){
	int w1 = ((ArestaF *)a)->w;
	int w2 = ((ArestaF *)b)->w;

	return w1-w2;
}

int main (){
	int n, m, R;

	scanf("%d%d%d", &n, &m, &R);

	for(int i = 1 ; i <= n ; i++)
		pai[i] = i;

	for(int i = 0 ; i < m ; i++){
		scanf("%d%d%d", &arestasF[i].u, &arestasF[i].v, &arestasF[i].w);
	}

	for(int i = 0 ; i < R ; i++)
		scanf("%d%d%d", &arestasR[i].u, &arestasR[i].v, &arestasR[i].w);

	qsort(arestasF, m, sizeof(ArestaF), compar2);
	qsort(arestasR, R, sizeof(ArestaR), compar1);

	int r = 0;

	for(int i = 0 ; i < m ; i++){
		r += join(arestasF[i].u, arestasF[i].v, arestasF[i].w);				
	}
	
	for(int i = 0 ; i < R ; i++){
		r += join(arestasR[i].u, arestasR[i].v, arestasR[i].w);				
	}

	printf("%d\n", r);
	
	return 0;
}
