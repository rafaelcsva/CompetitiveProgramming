#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	for(int test = 1 ; test <= t ; test++){
		int fn = 0;
		int n, k;

		scanf("%d %d", &n, &k);

		for(int i = 1 ; i < n ; i++){
			fn = (k + fn) % (i + 1);
		}

		printf("Case %d: %d\n", test, fn + 1);
	}

	return 0;
}