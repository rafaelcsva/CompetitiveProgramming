#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 500;
	int ans = 0;

	for(int i = 1 ; i <= 500 ; i++){
		ans = max(ans, (n - i + 1) * i);
	}

	printf("%d\n", ans);
}