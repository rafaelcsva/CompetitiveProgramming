#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
int n, d, c;

const int N = 20;
double dp[20][20][20];
bool used[20][20][20];
const int M = 51;
int a[M], b[M];
int cnt[M];

ll pas[M][M];
ll tot = 0LL;

double solve(int qtd1, int qtd2, int qtd3){
	if(qtd1 + qtd3 == 0 || qtd2 + qtd3 == 0){
		return 0.0;
	}

	bool &us = used[qtd1][qtd2][qtd3];
	double &ans = dp[qtd1][qtd2][qtd3];

	if(us){
		return ans;
	}

	us = true;

	ans = 0.0;
	double sum = 0.0;

	int rest = n - qtd1 - qtd2 - qtd3;

	for(int i = 0 ; i <= qtd1 ; i++){
		for(int j = 0 ; j <= qtd2 ; j++){
			for(int k = 0 ; k <= qtd3 ; k++){
				if(i + j + k > d){
					break;
				}

				if((i + j + k) + rest < d){
					continue;
				}
				if(i == 0 && j == 0 && k == 0){
					continue;
				}

				// printf("prob = %lf %d %d %d\n", 
				// 	((double(pas[qtd1][i]) / tot) * pas[qtd2][j] * pas[qtd3][k] * pas[rest][d - i - j - k]), i, j, k);
				// assert(pas[qtd1][i] * pas[qtd2][j] * pas[qtd3][k] * pas[rest][d - i - j - k] > 0);

				// printf("%lld\n", pas[qtd1][i] * pas[qtd2][j] * pas[qtd3][k] * pas[rest][d - i - j - k]);

				sum += (1.0 + solve(qtd1 - i, qtd2 - j, qtd3 - k)) 
					* ((double(pas[qtd1][i])) * pas[qtd2][j] * pas[qtd3][k] * pas[rest][d - i - j - k]) / double(tot);
			}
		}
	}

	if(rest >= d){
		ll coef = pas[rest][d];

		ans = ((sum * double(tot) + (double(coef) / tot) * double(tot)) ) / double(tot - coef);
	}else{
		ans = sum;
	}

	return ans;
}

int main(){
	pas[0][0] = 1LL;

	for(int i = 1 ; i < M ; i++){
		pas[i][0] = pas[i][i] = 1LL;

		for(int j = 1 ; j < i ; j++){
			pas[i][j] = pas[i - 1][j] + pas[i - 1][j - 1];
		}
	}

	scanf("%d %d %d", &n, &d, &c);

	tot = pas[n][d];
	// printf("t:%lld %d %d\n", tot, n , d);

	for(int i = 0 ; i < c ; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	for(int i = 0 ; i < c ; i++){
		scanf("%d", &b[i]);
		
		cnt[b[i]]++;
	}

	int qtd1 = c;
	int qtd2 = c;
	int qtd3 = 0;

	for(int i = 0 ; i < c ; i++){
		if(cnt[a[i]] > 1){
			qtd1--;
			qtd2--;
			qtd3++;
		}
	}

	// printf("%d %d %d\n", qtd1, qtd2, qtd3);

	printf("%.10lf\n", solve(qtd1, qtd2, qtd3));

	return 0;
}