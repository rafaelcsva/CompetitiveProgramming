#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		long long a, b;

		scanf("%lld %lld", &a, &b);

		if(a < b){
			swap(a, b);
		}

		a = a - b * 2;

		if(a <= 0LL && (a % 3) == 0LL){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}