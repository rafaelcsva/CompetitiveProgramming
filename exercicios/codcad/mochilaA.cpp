#include <bits/stdc++.h>

#define MAXIMO	2010

using namespace std;

typedef struct {
	int first, second;
}Carne;

int main (){
	int p, n;
	Carne pf[MAXIMO];

	scanf("%d%d", &p, &n);
	
	int dp[n+2][p+2];

	for(int i = 0 ; i <= n ; i++)
		dp[i][0] = 0;

	for(int j = 0 ; j <= p ; j++)
		dp[0][j] = 0; 

	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &pf[i].first, &pf[i].second);
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p;j++)
		{
			if(pf[i-1].first<=j)
			{
				dp[i][j]=max(pf[i-1].second+dp[i-1][j-pf[i-1].first],dp[i-1][j]);
			}
			else 
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	printf("%d\n", dp[n][p]);

	return 0;
}
