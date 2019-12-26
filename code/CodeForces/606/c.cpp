#include <bits/stdc++.h>

using namespace std;

map< int, int > mp;
vector< vector< int > > mat;
typedef pair< int, int >	pii;
vector< pii > v;

bool compar(pii a, pii b){
	return a.second < b.second;
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		int ai;

		scanf("%d", &ai);

		mp[ai]++;
	}

	for(auto u: mp){
		v.push_back(u);
	}

	v.push_back({0, 0});
	sort(v.begin(), v.end(), compar);

	for(int i = 1 ; i < v.size() ; i++){
		v[i].second += v[i - 1].second;
	}

	int r1 = 1, r2 = 1;
	int ans = 1;

	for(int i = 1 ; i <= n ; i++){
		int lo = 0, hi = int(v.size()) - 1;
		int r = 0;

		while(lo <= hi){
			int mid = (lo + hi) >> 1;

			if(v[mid].second - v[mid - 1].second <= i){
				r = mid;
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}

		int tot = v[r].second + (int(v.size()) - r - 1) * i;
		// printf("tot = %d\n", tot);

		int o = tot / i;

		if(o >= i){
			if(ans < i * o){
				ans = i * o;
				r1 = i;
				r2 = o;
			}
		}
	}

	for(int i = int(v.size() - 1) ; i >= 1; i--){
		v[i].second -= v[i - 1].second;
	}


	printf("%d\n", ans);

	printf("%d %d\n", r1, r2);

	int cur = 1;

	mat.resize(r1);

	for(int i = 0 ; i < r1 ; i++){
		mat[i].resize(r2);
	}

	for(int i = 1 ; i <= r2 ; i++){
		v[cur].second = min(v[cur].second, r1);

		int l = 0;
		int c = i - 1;
		int taked = 0;

		while(l < r1){
			mat[l][c] = v[cur].first;
			v[cur].second--;

			c = (c + 1) % r2;

			if(v[cur].second == 0){
				cur++;

				if(cur < v.size())
					v[cur].second = min(v[cur].second, r1);
			}

			l++;
		}
	}

	for(int i = 0 ; i < r1 ; i++){
		for(int j = 0 ; j < r2 ; j++){
			printf("%d ", mat[i][j]);
		}

		printf("\n");
	}

	return 0;
}