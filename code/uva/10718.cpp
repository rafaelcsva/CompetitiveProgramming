#include <bits/stdc++.h>

using namespace std;

typedef long long int	ui;

ui n, l, u;

ui make(ui m, ui bit){
	for(ui k = bit - 1LL ; k >= 0LL ; k--){
		ui at = 1LL << k;
		
		if(m & at){
			m -= at;
		}
		
		if(k == 0LL)
			break;
	}
	
	return m;
}

int main (){

	while(scanf("%lld%lld%lld", &n, &l, &u) != EOF){
		ui m = 0LL;
		
		for(ui i = 32LL ; i >= 0LL ; i--){
			
			ui add = 1LL << i;
			ui cand = 0LL;
			
			if(((n & add) == 0LL && (m | add) <= u) || (m | add) <= l){
				m = m | add;
			}

		}
		
		printf("%lld\n", m);
			
	}
	
	return 0;
}
