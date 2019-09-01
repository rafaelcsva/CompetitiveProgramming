#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int cost[N];
int lft[N], rg[N];

int calc(char c){
	return min(c - 'A', 1 + 'Z' - c);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;

	while(t--){
		memset(lft, -1, sizeof lft);
		memset(rg, -1, sizeof rg);

		string s;

		cin >> s;

		int n = s.length();

		int tot = 0;
		int qtd = 0;

		for(int i = 1 ; i <= n ; i++){
			cost[i] = calc(s[i - 1]);
			tot += cost[i];

			if(cost[i]) qtd++;
		}

		int lf = 1;
		int best = int(1e8);

		if(qtd == 1){
			for(int i = 1 ; i <= n ; i++){
				if(cost[i]){
					best = min(i - 1, n - i + 1);
				}
			}
		}else{
			cost[1] = 1;

			for(int i = 2 ; i <= n ; i++){
				if(cost[i]){
					rg[lf] = i;
					lft[i] = lf;
					lf = i;
				}
			}

			for(int i = 1 ; i <= n ; i++){
				if(cost[i]){
					if(rg[i] != -1){
						best = min(best, min(2 * (i - 1) + n + 1 - rg[i], 2 * (n - rg[i] + 1) + i - 1));
					}else{
						best = min(best, i - 1);
					}
				}
			}
		}

		printf("%d\n", tot + best);
	}

	return 0;
}