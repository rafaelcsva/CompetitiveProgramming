#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
typedef pair< int, int >	pii;

const int N = 1010;
char tab[N][N];
char rev[N][N];
ll answer[N][N];
int marked[N][N];
ll cnt[N * N];
int comp = 1;
int n, m;
vector< pii > adj[N][N];
vector< pii > topological_sort;
int current = -1, ci, cj;
ll carry = 0LL;
ll pref[N][N];

bool ok(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

ll dfs(int i, int j, ll sum){
	// printf("aqui com %d, %d\n", i, j);
	if(answer[i][j] != -1LL){
		return answer[i][j];
	}

	marked[i][j] = comp;

	pref[i][j] = sum - 1;

	int ti = i, tj = j;

	if(tab[i][j] == 'N'){
		ti = i - 1;
	}else if(tab[i][j] == 'S'){
		ti = i + 1;
	}else if(tab[i][j] == 'E'){
		tj = j + 1;
	}else{
		tj = j - 1;
	}

	answer[i][j] = 1LL;

	if(ok(ti, tj)){
		if(marked[ti][tj] == comp){
			current = 1;
			ci = ti;
			cj = tj;
			carry = sum - pref[ci][cj];
		}else{
			answer[i][j] += dfs(ti, tj, sum + 1LL);
		}
	}

	if(current != -1){
		// printf("aqui!\n");
		answer[i][j] = carry;

		if(ci == i && cj == j){
			ci = cj = current = -1;
		}
	}
	// printf("%d, %d %lld\n", i, j, answer[i][j]);
	return answer[i][j];
}

int main(){
	memset(answer, -1, sizeof answer);

	scanf("%d %d", &n, &m);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			scanf("\n%c", &tab[i][j]);
		}
	}

	ll sum = 0LL;
	// memset(marked, 0, sizeof marked);
	// printf("aqui\n");

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			sum += dfs(i, j, 1LL);
			comp++;
			// printf("%d, %d %lld\n", i, j, get_resp(i, j));
		}
	}

	printf("%lld\n", sum);

	return 0;
}