#include <bits/stdc++.h>

using namespace std;

const int N = 110;
long long a[N];
int n;
set< long long > st;

bool can(long long x){
	int e = __builtin_popcount(x ^ a[0]);

	for(int i = 1 ; i < n ; i++){
		int d = __builtin_popcount(x ^ a[i]);

		// printf("%d, %d\n", d, e);

		if(d != e) return false;
	}

	return true;
}

int main(){
	long long x = 0LL;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);

		if(st.find(a[i]) == st.end())
			x ^= a[i];

		st.insert(a[i]);
	}

	// printf("x: %lld\n", x);

	bool ok = false;

	do{
		if(can(x)){
			ok = true;
			break;
		}

		x >>= 1LL;

	}while(x != 0LL);

	if(can(0)){
		ok = true;
	}
	
	if(ok){
		printf("%lld\n", x);
	}else{
		printf("-1\n");
	}

	// long long ee = 1073709057LL >> 2;

	// while(ee != 0){
	// 	printf("%d", ee & 1);
	// 	ee >>= 1LL;
	// }
	// printf("\n");

	return 0;
}