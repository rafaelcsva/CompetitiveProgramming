#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d;

	scanf("%d %d", &n, &d);

	int q = 2 * d + 1;
	// printf("%d %d\n", q, n + q - 1);

	printf("%d\n", (n + q - 1) / q);

	return 0;
}