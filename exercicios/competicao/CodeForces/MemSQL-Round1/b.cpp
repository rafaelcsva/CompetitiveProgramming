#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;

	scanf("%d", &n);

	int p = (int)floor(sqrt(n));
	int x = (int)ceil(sqrt(n));
	int r = p*2+x*2;

	//printf("%d\n", p);

	if(p*x < n){
		r += 2;
	}

	printf("%d\n", r);

	return 0;

}