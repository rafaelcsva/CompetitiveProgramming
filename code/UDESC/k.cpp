#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%s\n", (n % k == 0) ? "Vinicius" : "Peter");

	return 0;
}