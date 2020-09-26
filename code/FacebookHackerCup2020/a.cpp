#include <bits/stdc++.h>

using namespace std;

const int N = 60;
int prei[N];
int preo[N];

int main(){
	int t;
	int test = 1;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 1 ; i <= n ; i++){
			char c;

			scanf("\n%c", &c);

			prei[i] = (c == 'N') + prei[i - 1];
		}

		for(int i = 1 ; i <= n ; i++){
			char c;

			scanf("\n%c", &c);

			preo[i] = (c == 'N') + preo[i - 1];
		}

		printf("Case #%d:\n", test++);

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(i == j){
					printf("Y");
				}else{
					if(i < j){
						int a = preo[j - 1] - preo[i - 1];
						int b = prei[j] - prei[i];

						if(a == 0 && b == 0){
							printf("Y");
						}else{
							printf("N");
						}
					}else{
						int a = prei[i - 1] - prei[j - 1];
						int b = preo[i] - preo[j];
						// if(i == 5 && j == 4){
						// 	printf("%d %d\n", a, b);
						// }
						if(a == 0 && b == 0){
							printf("Y");
						}else{
							printf("N");
						}
					}
				}
			}

			printf("\n");
		}
	}

	return 0;
}