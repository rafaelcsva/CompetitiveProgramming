#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;

typedef struct{
	lli w, ind;
}Item;

const int N = 10500, M = 110;
const lli inf = (lli) -1e9;
Item itens[110];
int used[N][M];
lli dp[N][M];
int m, n, t;

lli solve(lli k, int i){
	
	if(k > m + 200LL){
		return inf;
	}
	
	if(i == n){
		if(k <= m || k > 2000LL){
			return 0LL;
		}
		
		return inf;
	}
	
	lli &ans = dp[k][i];
	
	if(used[k][i] == t){
		return ans;
	}
	
	used[k][i] = t;
	
	return ans = max(solve(k + itens[i].w, i + 1) + itens[i].ind, solve(k, i + 1));
}

int main (){
	while(scanf("%d%d", &m, &n) != EOF){
		t++;
		
		for(int i = 0 ; i < n ; i++){
			scanf("%lld%lld", &itens[i].w, &itens[i].ind);
		}
		
		printf("%lld\n", solve(0LL, 0));
	}

	return 0;
}
