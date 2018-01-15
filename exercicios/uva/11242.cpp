#include <bits/stdc++.h>

using namespace std;

const int N = 110;
set<double>ratios;
double f[N];

int main (){
	int n, r;
	
	while(scanf("%d", &n)){
		if(n == 0){
			break;
		}
		
		scanf("%d", &r);
		
		for(int i = 0 ; i < n; i++){
			scanf("%lf", &f[i]);	
		}
		
		for(int i = 0 ; i < r ; i++){
			double ri;
			
			scanf("%lf", &ri);
			
			for(int k = 0 ; k < n ; k++){
				ratios.insert(ri / f[k]);
			}
		}
		
		double ans = 0.0;
		
		for(set<double>::iterator it = next(ratios.begin()) ; it != ratios.end() ; it = next(it)){
			ans = max(ans, *it / *(prev(it)));		
		}
		
		printf("%.2f\n", ans);
		
		ratios.clear();
	}

	return 0;
}
