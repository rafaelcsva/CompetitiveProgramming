#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int cnt[2][N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 1 ; i <= n ; i++){
			char x;

			scanf("\n%c", &x);
			x -= '0';

			cnt[i & 1][x & 1]++;
		}

		if(n & 1){
			if(cnt[1][1]){
				printf("1\n");
			}else{
				printf("2\n");
			}
		}else{
			if(cnt[0][0]){
				printf("2\n");
			}else{
				printf("1\n");
			}
		}

		memset(cnt, 0, sizeof cnt);
	}

	return 0;
}