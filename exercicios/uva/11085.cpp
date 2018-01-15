#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int row[N], v[N];
int tmprow[N];
int ans = N * N;

bool isValid(int pos, int r){
	for(int i = 0 ; i < pos ; i++){
		if(tmprow[i] == r || abs(i - pos) == abs(tmprow[i] - r)){
			//printf("-> %d %d %d %d\n", tmprow[i], i, r, pos);
			return false;
		} 
	}
	
	return true;
}

void backtracking(int pos, int steps){
	if(pos == N){
		
		ans = min(ans, steps);
		
	}else{
		for(int r = 0 ; r < 8 ; r++){
			if(isValid(pos, r)){
				tmprow[pos] = r;
				
				backtracking(pos + 1, steps + (row[pos] != r));
			}
		}
	}
}

int main (){
	int test = 1;
	
	while(scanf("%d", &row[0]) != EOF){
		row[0]--;
		
		for(int i = 1 ; i < 8 ; i++){
			scanf("%d", &row[i]);
			row[i]--;
		}
		
		backtracking(0, 0);
		
		printf("Case %d: %d\n", test++, ans);
		
		ans = N * N;
	}

	return 0;
}
