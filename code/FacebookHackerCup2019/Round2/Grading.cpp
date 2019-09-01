#include <bits/stdc++.h>

using namespace std;

const int N = 601, M = 300;
int dp[N][M * M + 1];
char tab[N][N];
int used[N][M * M + 1];
int pt[N];
int con[N];
int cost[N];
int pnt = 0;
int test;
const int inf = 1e6 + 10;

int solve(int u, int have){
	if(have < 0){
		return inf;
	}

	if(u >= pnt - 1){
		return 0;
	}

	if(used[u][have] == test){
		return dp[u][have];
	}

	used[u][have] = test;

	return dp[u][have] = min({solve(u + 1, have) + 1, solve(u + 2, have - con[u + 1]), solve(u + 3, have - cost[u]) + 1});
}

int main(){
	int t;

	scanf("%d", &t);

	for(test = 1 ; test <= t ; test++){
		int h, s, k;

		scanf("%d %d %d", &h, &s, &k);

		for(int i = 0 ; i < s ; i++){
			pt[i] = 0;
		}

		for(int i = 0 ; i < h ; i++){
			scanf("\n%s", tab[i]);
		}
		// printf("%s\n", tab[0]);

		bool check = true;
		int pass = 1;
		pnt = 0;

		while(check){
			cost[pnt] = 0;
			int sum = 0;
			check = false;

			for(int i = 0 ; i < s ; i++){
				int tmp = pt[i];
				while(pt[i] < h && tab[pt[i]][i] == char('A' + pass)){
					sum++;
					pt[i]++;
				}

				if(pt[i] < h){
					check = true;
					if(pnt)
						cost[pnt - 1] += pt[i] - tmp;
					
				}
			}

			printf("%d %c\n", sum, char('A' + pass));

			if(pnt){
				printf("%d %d\n", cost[pnt - 1], sum);
			}

			pass = (pass + 1) & 1;
			con[pnt++] = sum;
		}

		printf("Case #%d:", test);

		for(int i = 0 ; i < k ; i++){
			int li;

			scanf("%d", &li);

			if(pnt == 1){
				printf(" 1");
			}else{
				printf(" %d", 1 + min(solve(0, li), solve(1, li - con[0])));
			}
		}

		printf("\n");
	}

	return 0;
}
