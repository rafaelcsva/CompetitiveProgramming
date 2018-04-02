#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli v[1010];

int main (){
	int n = 0;
	
	while(scanf("%lld", &v[n++]) != EOF){
		if(v[n - 1] == -999999){
			n--;
			
			lli ans = v[n - 1];
			
			for(int i = 0 ; i < n ; i++){
				lli tmp = 1;
				for(int j = i ; j < n ; j++){
					tmp *= v[j];
					
					ans = max(ans, tmp);
				}
			}
			
			printf("%lld\n", ans);
			
			n = 0;
			
		}
	}	
	
	return 0;
		
}
