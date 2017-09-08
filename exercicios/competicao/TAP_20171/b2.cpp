#include <stdio.h>
#include <string.h>

int main (){
	double valores[101];
	int verificado[101];
	
	int i, j;
	int n;
	
	for(i = 0 ; i <= 100 ; i++)
		valores[i] = i;
		
	for(i = 0 ; i <= 100 ; i++)
		verificado[i] = 0;
		
	scanf("%d", &n);
	char operacao[10];
	int k;
	int qtd = 0;
	
	for(i = 0 ; i < n ; i++){
		scanf("\n%s", operacao);
		scanf("%d", &k);
		
		if(!strcmp(operacao, "SUBTRACT")){
			for(j = 1 ; j <= 100 ; j++){
				if(verificado[j]){
					continue;
				}
				
				valores[j] -= k;
				int inteiro = valores[j];
				
				if(valores[j] < 0||valores[j]-inteiro!=0){
					qtd++;
					verificado[j] = 1;
				}
			}
		}
		else if(!strcmp(operacao, "DIVIDE")){
			for(j = 1 ; j <= 100 ; j++){
				if(verificado[j]){
					continue;
				}
				
				valores[j] /= k;
				int inteiro = valores[j];
				
				if(valores[j] < 0||valores[j]-inteiro!=0){
						qtd++;
						verificado[j] = 1;
				}
			}
		}
		else if(!strcmp(operacao, "ADD")){
			for(j = 1 ; j <= 100 ; j++){
				valores[j] += k;
			}
		}
		else{
			for(j = 1 ; j <= 100 ; j++){
				valores[j] *= k;
			}
		}
	}
	
	
	printf("%d\n", qtd);
	
	return 0;
}
