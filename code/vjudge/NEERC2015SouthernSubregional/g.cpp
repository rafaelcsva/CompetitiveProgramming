#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
int a[N];

int main(){
	int n, k;

	scanf("%d %d", &n, &k);

	int mn = 0;

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
	}

	int sum = 0;

	for(int i = 0 ; i < k ; i++){
		sum += a[i];
	}

	int cost = 0;

	// printf("%d\n", mn);

	for(int i = 0 ; i <= n - k ; i++){
		// printf("%d\n", sum);
		if(sum >= 0){
			int j = i + k - 1;

			while(sum >= 0){
				int poss = a[j] - mn;

				if(poss >= sum + 1){
					cost += sum + 1;
					a[j] -= (sum + 1);
					sum = -1;
					// printf("j: %d\n", j);
				}else{
					sum -= poss;
					cost += poss;
					a[j] = mn;
					// printf("j> %d\n", j);
				}
				j--;
			}
		}

		sum -= a[i];
		sum += a[i + k];
	}

	printf("%d\n", cost);

	for(int i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}