#include <bits/stdc++.h>

using namespace std;

#define MAXIMO	2000100

int arvore[MAXIMO];
int valores[MAXIMO];


void ConstruirSegment(int no, int i, int j){
	if(i == j){
		arvore[no] = valores[i] > 0 ? 1 : (valores[i] == 0 ? 0 : -1);
	}
	else{
		ConstruirSegment(no*2, i, (i+j)/2);
		ConstruirSegment(no*2+1, (i+j)/2+1, j);

		arvore[no] = arvore[no*2]*arvore[no*2+1];
	}
}

void AtualizaValor(int no , int i, int j, int posicao, int valor){
	if(i > posicao || j < posicao)
		return;

	if(i == j){
		arvore[no] = valor > 0 ? 1 : (valor == 0 ? 0 : -1);	
	}else{
		int esquerda = no*2;
		int direita = no*2+1;
		int meio = (i+j)/2;
		
		AtualizaValor(esquerda, i, meio, posicao, valor);
		AtualizaValor(direita, meio+1, j, posicao, valor);
		
		arvore[no] = arvore[esquerda]*arvore[direita];
	}
}

int ConsultaIntervalo(int no, int i, int j, int I, int V){
	if(i > V || j < I)
		return 1;

	if(i >=I && j <= V){
		return arvore[no];
	}else{	
		int meio = (i+j)/2;
		int direita = no*2+1;
		int esquerda = no*2;
		
		int a = ConsultaIntervalo(esquerda, i, meio, I, V);
		int b = ConsultaIntervalo(direita, meio+1, j, I, V);

		return a*b;
	} 
}

int main (){
	int n, k;

	while(scanf("%d%d", &n, &k)!=EOF){
		int x;

		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &valores[i]);
		}

		ConstruirSegment(1, 1, n);
		
		char c;

		for(int i = 1 ; i <= k ; i++){
			scanf("\n%c", &c);
			int I, V;
	
			scanf("%d%d", &I, &V);

			if(c == 'C'){
				AtualizaValor(1, 1, n, I, V);									
			}
			else if(c == 'P'){
				int resposta = ConsultaIntervalo(1, 1, n, I, V);

				if(resposta > 0)
					printf("+");
				else if(resposta == 0)
					printf("0");
				else 
					printf("-");
			}
		}

		printf("\n");
		
	}

	return 0;
}
