#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int TENT = 9;
int bel[N];
vector< int > v[TENT][2];

void solve(int l, int r, int deep){
	// cout << l << " " << r << endl;
	if(l == r){
		v[deep][0].push_back(l);
	}else{
		int mid = (l + r) >> 1;

		for(int i = l ; i <= mid ; i++){
			v[deep][0].push_back(i);
		}

		for(int i = mid + 1 ; i <= r ; i++){
			v[deep][1].push_back(i);
		}

		solve(l, mid, deep + 1);
		solve(mid + 1, r, deep + 1);
	}
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		solve(1, n, 0);

		int best = 0;

		for(int i = 0 ; i < TENT ; i++){
			if(v[i][0].size() && v[i][1].size()){
				printf("%lu %lu", v[i][0].size(), v[i][1].size());

				for(int j = 0 ; j < v[i][0].size() ; j++){
					printf(" %d", v[i][0][j]);
				}

				for(int j = 0 ; j < v[i][1].size() ; j++){
					printf(" %d", v[i][1][j]);
				}

				printf("\n");

				fflush(stdout);

				int x;

				scanf("%d", &x);

				assert(x != -1);

				best = max(best, x);
			}
		}

		for(int i = 0 ; i < TENT ; i++){
			v[i][0].clear();
			v[i][1].clear();
		}

		printf("-1 %d\n", best);
		fflush(stdout);
	}

	return 0;
}