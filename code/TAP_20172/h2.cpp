#include <bits/stdc++.h>
#define MAXIMO	1000100

using namespace std;

int dp[MAXIMO];

typedef struct Wave{
	int m, f, w;
}Wave;

Wave waves[MAXIMO];
	
int maior = -1;

int solve(int t){
	if(t > maior)
		return 0;
	
	if(dp[t] != -1)
		return dp[t];

	
	int n1 = solve(t+1);
	int fMax = n1;

	if(waves[t].m != 0){
		fMax = max(n1, waves[t].f+solve(waves[t].m+waves[t].w));
	}

	return dp[t] = fMax;
}

int main (){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < MAXIMO; i++)
		dp[i] = -1;

	for(int i = 0 ; i < n ; i++){
		int x;
		
		scanf("%d", &x);

		maior = max(x,maior);

		waves[x].m = x;

		scanf("%d%d", &waves[x].f, &waves[x].w);
	}	

	printf("%d\n", solve(0));

	
}
