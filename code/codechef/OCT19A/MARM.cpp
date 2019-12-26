#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
int a[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;
		long long k;

		scanf("%d %lld", &n, &k);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		for(int i = 0 ; i < (n + 1) / 2 ; i++){
			long long kk = (k / n);
			long long e = n;

			if(k % n >= i + 1){
				kk++;
			}

			int o = n - (i % n) - 1;

			if(i != o){
				kk += (k / n);
			}

			if(i != o && (k % n) >= o + 1){
				kk++;
			}

			if(i == o && kk){
				a[i] = 0LL;
				continue;
			}
			
			kk %= 6LL;

			for(int d = 0 ; d < int(kk) ; d++){
				if(d & 1){
					a[o] = a[i] ^ a[o];
				}else{
					a[i] = a[i] ^ a[o];
				}
			}
		}

		for(int i = 0 ; i < n ; i++){
			printf("%d ", a[i]);
		}

		printf("\n");
	}

	return 0;
}