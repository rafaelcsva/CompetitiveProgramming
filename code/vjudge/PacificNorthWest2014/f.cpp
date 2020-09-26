#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	while(scanf("%d", &n) != EOF){
		if(n == -1) break;

		set< int > divs;

		for(int i = 1 ; i * i <= n ; i++){
			if(n % i == 0){
				divs.insert(i);
				divs.insert(n / i);
			}
		}

		int tn = n;

		for(auto u: divs){
			if(u != tn){
				n -= u;
			}
		}

		if(n == 0){
			printf("%d = 1", tn);

			for(auto u: divs){
				if(u == 1) continue;
				if(u == tn) break;

				printf(" + %d", u);
			}

			printf("\n");
		}else{
			printf("%d is NOT perfect.\n", tn);
		}
	}

	return 0;
}