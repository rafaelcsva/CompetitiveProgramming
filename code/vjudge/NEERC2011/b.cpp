#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5);
char s[N];

void seq(int n, int m){
	// printf("here\n");

	for(int i = 0 ; i < n ; i++){
		for(int k = m - 1 ; k >= 0 ; k--){
			int e = 1 << k;

			if(e & i){
				printf("1");
			}else{
				printf("0");
			}
		}

		printf("\n");
	}
}

int main(){
	int n;

	while(scanf("%d", &n) != EOF){
		int d = 1;
		int m = 0;

		while(d < n){
			d *= 2;
			m++;
		}

		// printf("%d\n", m);

		if(d == n){
			seq(n, m);
		}else{
			int pa = (1 << (m - 1));
			int i = 0;

			// printf("pa: %d %d\n", (pa - i - 1) * 2, m - 2);

			while((pa - i - 1) * 2 + i + 1 >= n){
				// printf("i: %d\n", i);

				for(int j = m - 2 ; j >= 0 ; j--){
					int e = 1 << j;

					if(i & e){
						printf("1");
					}else{
						printf("0");
					}
				}

				printf("\n");
				i++;
				// printf(" %d\n", (pa - i - 1) * 2 + i);
			}
			
			int add = i;

			for(int k = i ; k < pa ; k++){
				for(int j = 0 ; j <= 1 && add < n; j++){
					int num = (k << 1) + j;

					for(int j = m - 1 ; j >= 0 ; j--){
						int e = 1 << j;

						if(num & e){
							printf("1");
						}else{
							printf("0");
						}
					}

					printf("\n");

					add++;
				}
			}

			// printf("%d %d\n", add, n);
		}
	}

	return 0;
}