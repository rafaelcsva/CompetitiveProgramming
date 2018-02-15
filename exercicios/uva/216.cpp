#include <bits/stdc++.h>

using namespace std;

typedef struct{
	int x, y;
}PC;

const double inf = 1e9;
const int N = 10, S = 300;
PC comp[N];
double dp[N][S];
int used[N][S], t, n;

double dis(int k, int i){
	int dx = abs(comp[k].x - comp[i].x);
	int dy = abs(comp[i].y - comp[k].y);
	
	return sqrt(dx * dx + dy * dy);
}

double solve(int k, int s){
	double &ans = dp[k][s];
	
	if(used[k][s] == t){
		return ans;
	}
	
	ans = -1.0;
	used[k][s] = t;
	for(int i = 0 ; i < n ; i++){

		int chk = 1 << i;
		
		if((s & chk) == 0){
				
			if(ans == -1.0){
				ans = solve(i, s | chk) + dis(k, i) + 16.0;
			}else{
				ans = min(ans, solve(i, s | chk) + dis(k, i) + 16.0);
			}	
		}
	}
	
	return ans = max(ans, 0.0);
}

void printDP(int k, int s){
	for(int i = 0 ; i < n ; i++){
		int chk = 1 << i;
		
		if((s & chk) == 0){
			if(dp[k][s] == dp[i][s | chk] + dis(k, i) + 16.0){
				printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", comp[k].x, comp[k].y, comp[i].x, comp[i].y, dis(k, i) + 16.0);
				printDP(i, s | chk);
				break;
			}
		}
	}
}

int main (){
	
	while(scanf("%d", &n) && n){
		t++;
		
		printf("**********************************************************\n");
		
		printf("Network #%d\n", t);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d%d", &comp[i].x, &comp[i].y);
		}
		
		double ans = 1e9;
		
		for(int i = 0 ; i < n ; i++){
			ans = min(ans, solve(i, 1 << i));
		}
		
		for(int i = 0 ; i < n ; i++){
			if(ans == dp[i][1 << i]){
				printDP(i, 1 << i);
				break;
			}
		}
			
		printf("Number of feet of cable required is %.2lf.\n", ans);
	}

	return 0;
}
