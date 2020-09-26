#include <bits/stdc++.h>

using namespace std;

int cnt[2];

int main(){
	int t;

	scanf("%d", &t);

	int test = 1;

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			char c;

			scanf("\n%c", &c);

			cnt[c - 'A']++;
		}

		printf("Case #%d: ", test++);

		if(abs(cnt[0] - cnt[1]) == 1){
			printf("Y\n");
		}else{
			printf("N\n");
		}

		memset(cnt, 0, sizeof cnt);
	} 

	return 0;
}