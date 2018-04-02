#include <bits/stdc++.h>

#define MAXIMO	1010

using namespace std;

int main (){
	int n;
	int valores[MAXIMO];
	int dp[MAXIMO];

	scanf("%d", &n);

	for(int i = 0 ;i < n ; i++)
		scanf("%d", &valores[i]);

	int maior = 0;

	for(int i = 0; i < n ; i++){
		dp[i] = 1;

		for(int j = 0 ; j < i ; j++){
			if(valores[i] >= valores[j]&&dp[i] < dp[j]+1){
				dp[i] = dp[j] + 1;
			}
			
		}
		maior = max(maior, dp[i]);

	}	

	printf("%d\n", maior);

	return 0;
}
