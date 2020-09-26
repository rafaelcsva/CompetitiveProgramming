#include <bits/stdc++.h>

using namespace std;

int main(){
	int d, r, t;

	scanf("%d %d %d", &d, &r, &t);

	for(int i = max(d, 4) ; i <= 100 ; i++){
		int sum = ((4 + i) * (i - 4 + 1)) / 2;
		int j = i - d;
		int sum1 = ((3 + j) * (j - 3 + 1)) / 2;

		if(sum + sum1 == r + t){
			printf("%d\n", r - sum);
			break;
		}
	}

	return 0;
}