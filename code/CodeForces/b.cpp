#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int dig[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		int tn = n;

		for(int i = 0 ; i < n ; i++){
			if(tn > 0){
				dig[i] = 8;
				tn -= 4;
			}else{
				dig[i] = 9;
			}
		}

		reverse(dig, dig + n);

		for(int i = 0 ; i < n ; i++){
			printf("%d", dig[i]);
		}

		printf("\n");
	}

	return 0;
}