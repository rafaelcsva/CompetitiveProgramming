#include <bits/stdc++.h>

using namespace std;

const int N = int(5e3 + 10);
const int M = int(1e5 + 10);
int bit[M];
int c[N][N];
const int inf = int(1e9);
int h[N];
vector< int > dp_before(N), dp_cur(N);

void compute(int l, int r, int optl, int optr, vector< int > &dp_cur, vector< int > &dp_before){	
	if(l > r){
		return;
	}

	int mid = (l + r) >> 1;
	pair< int , int > best = {inf, -1};

	for(int k = optl ; k <= min(mid, optr) ; k++){
		best = min(best, {dp_before[k] + c[k + 1][mid], k});
	}

	dp_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt, dp_cur, dp_before);
	compute(mid + 1, r, opt, optr, dp_cur, dp_before);
}

int LSOne(int x){
	return x & (-x);
}

int query(int x){
	int sum = 0;

	while(x > 0){
		sum += bit[x];
		x -= LSOne(x);
	}

	return sum;
}

void update(int x){
	while(x < N){
		bit[x] += 1;
		x += LSOne(x);
	}
}

int rsq(int l, int r){
	if(l > r){
		return 0;
	}

	return query(r) - query(l - 1);
}

int main(){
	int n, k;

	scanf("%d %d", &n, &k);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &h[i]);
	}

	for(int i = 0 ; i < n ; i++){
		update(h[i]);

		for(int j = i - 1 ; j >= 0 ; j--){
			c[j][i] = c[j + 1][i] + rsq(1, h[j] - 1);
			// printf("%d-%d = %d\n", j, i, c[j][i]);
			update(h[j]);
		}

		memset(bit, 0, sizeof bit);
	}

	for(int i = 0 ; i < n ; i++){
		dp_cur[i] = c[0][i];
	}

	int tk = k - 1;
	int d = 0;

	while(tk){
		if(d & 1){
			compute(0, n - 1, 0, n - 1, dp_cur, dp_before);
		}else{
			compute(0, n - 1, 0, n - 1, dp_before, dp_cur);
		}

		tk--;
		d++;
	}

	if((k & 1)){
		printf("%d\n", dp_cur[n - 1]);
	}else{
		printf("%d\n", dp_before[n - 1]);
	}

	return 0;
}