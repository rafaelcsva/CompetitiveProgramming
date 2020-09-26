#include <bits/stdc++.h>

using namespace std;

const int N = 60;
char s[110][N + 10];
int a[110];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		for(int i = 0 ; i < N ; i++){
			s[0][i] = 'a';
		}

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= a[i - 1] ; j++){
				s[i][j - 1] = s[i - 1][j - 1];
			}

			for(int j = a[i - 1] + 1 ; j <= N ; j++){
				s[i][j - 1] = ((s[i - 1][j - 1] - 'a') + 1) % 26 + 'a';
			}
		}

		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j < N ; j++){
				printf("%c", s[i][j]);
			}

			printf("\n");
		}
	}

	return 0;
}