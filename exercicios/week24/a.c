#include <stdio.h>

int main (){
	int numero;

	scanf("%d", &numero);

	int digito[7];

	int a, b;

	do{
		numero++;
		
		int aux = numero;
		for(int i = 0 ; i < 6; i++){
			digito[i] = aux%10;
			aux = aux/10;
		}

		a = digito[0] + digito[1] + digito[2];
		b = digito[3] + digito[4] + digito[5];

		if(numero == 555564)
			break;
		
	}while(a!=b);

	printf("%d\n", numero);

	return 0;
}
