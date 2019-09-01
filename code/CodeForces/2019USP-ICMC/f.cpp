#include <bits/stdc++.h>

using namespace std;

int main(){
	double prob = 0.0;

	int n;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		prob += double(i ) / double(n);
	}

	printf("%.10lf\n", prob);

	return 0;
}