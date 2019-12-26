#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		long long r, b, k;

		scanf("%lld %lld %lld", &r, &b, &k);

		if(r == b){
			printf("OBEY\n");
		}else{
			if(r < b){
				swap(r, b);
			}

			long long qtd = r / b;
			long long g = __gcd(r, b);

			long long qtd2 = (r - g - 1LL) / b + 1LL;

			if(r % b == 0LL){
				qtd--;
			}

			if(max(qtd, qtd2) < k){
				printf("OBEY\n");
			}else{
				printf("REBEL\n");
			}
		}
	}

	return 0;
}
