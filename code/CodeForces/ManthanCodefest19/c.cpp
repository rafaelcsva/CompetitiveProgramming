#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int cnt[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n * n ; i++){
		for(int j = 0 ; j <= 3 ; j++){
			if(i & (1 << j)){
				cnt[j]++;
			}
		}
	}

	for(int j = 0 ; j <= 3 ; j++){
		printf("%d ", cnt[j]);
	}

	printf("\n");

	return 0;
}