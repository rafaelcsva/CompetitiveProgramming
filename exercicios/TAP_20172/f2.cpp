#include <bits/stdc++.h>
#define	MAXIMO	100010
#define INF 99999999
using namespace std;

int main (){
	int n;
	int menor = -1;
	int Smenor = -1;

	int valores[MAXIMO];

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &valores[i]);
	}

	sort(valores, valores+n);

	int sumM = INF;

	for(int i = n/2-1 ; i >= 0 ; i--){
		if(valores[i]+valores[n-1-i] < sumM)
			sumM = valores[i]+valores[n-1-i];
	}

	printf("%d\n", sumM);

	return 0;
}
