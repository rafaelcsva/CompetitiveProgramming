#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;
int v[N];

typedef long long int	lli;

int main (){
	int t;
	
	scanf("%d", &t);

	while(t--){
		int n, k;

		scanf("%d%d", &n, &k);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}

		lli suml = v[0], sumt = 0, sumr = v[n - 1], ma = v[0];
		
		lli tmp = 0;
		lli tmpma = 0;

		for(int i = 0; i < n ; i++){
			tmp += (lli)v[i];
			tmpma = max(tmpma + ((lli)v[i]), (lli)v[i]);
			
			ma = max(ma, tmpma);

			suml = max(tmp, suml);	
		}
	
		sumt = tmp;
		tmp = 0;

		for(int i = n - 1 ; i >= 0 ; i--){
			tmp += (lli) v[i];
			
			sumr = max(sumr, tmp);			
		}

		if(k == 1){
			printf("%lld\n", ma);
			continue;	
		}

		lli opt = ma;
		opt = max(max(((lli) k) * sumt, max(sumr + suml, max(sumr, suml))), opt);
		opt = max(max((k - 1) * sumt + suml, sumr + (k - 1) * sumt), opt);

		opt = max((k - 2) * sumt + suml + sumr, opt);

		printf("%lld\n", opt); 
	}

	return 0;
}
