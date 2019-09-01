#include <bits/stdc++.h>

using namespace std;

const int N = 110;
typedef pair< int, int >	pii;
int a[N];
int n;
pii p[N];
int ans[N];

bool compar(pii a, pii b){
	if(a.first > b.first){
		return true;
	}else if(a.first < b.first){
		return false;
	}else{
		return a.second < b.second;
	}
}

bool is_possible(int tot, int mid, int i){
	for(int j = i + 1 ; j < n ; j++){
		tot -= min(mid, p[j].first);
	}

	return tot <= 0;
}

int main(){	
	int t;

	scanf("%d", &t);

	while(t--){
		int v;

		scanf("%d %d", &v, &n);

		int tot = 0;

		for(int i = 0 ; i < n ; i++){
			int ai;

			scanf("%d", &ai);

			tot += ai;
			p[i] = {ai, i};
		}

		if(tot < v){
			printf("IMPOSSIBLE\n");
			continue;
		}

		sort(p, p + n, compar);

		for(int i = 0 ; i < n ; i++){
			int lo = 0, hi = p[i].first;
			int r = -1;

			while(lo <= hi){
				int mid = (lo + hi) >> 1;

				if(is_possible(v - mid, mid, i)){
					r = mid;
					hi = mid - 1;
				}else{
					lo = mid + 1;
				}
			}

			// printf("%d, %d, %d\n", i, r, p[i].first);

			assert(r != -1);

			ans[p[i].second] = r;

			v -= r;
		}

		for(int i = 0 ; i < n ; i++){
			char c = (i == n - 1) ? '\n' : ' ';
			printf("%d%c", ans[i], c);
		}
	}

	return 0;
}