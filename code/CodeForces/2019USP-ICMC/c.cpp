#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;

const int N = int(2100);

int bit[N];
bool ver[N][N];
pii p[N];

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

void update(int x, int val = 1){
	while(x < N){
		bit[x] += val;
		x += LSOne(x);
	}
}

int rsq(int l, int r){
	return query(r) - query(l - 1);
}

vector< int > coordx, coordy;

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		scanf("%d %d", &p[i].first, &p[i].second);
		coordx.push_back(p[i].first);
		coordy.push_back(p[i].second);
	}

	sort(coordy.begin(), coordy.end());
	sort(coordx.begin(), coordx.end());

	sort(p + 1, p + 1 + n);

	for(int i = 1 ; i <= n ; i++){
		p[i].first = lower_bound(coordx.begin(), coordx.end(), p[i].first) - coordx.begin() + 1;
		p[i].second = lower_bound(coordy.begin(), coordy.end(), p[i].second) - coordy.begin() + 1;
		ver[p[i].first][p[i].second] = true;
	}

	int ans = 0;

	for(int i = 1 ; i <= n ; i++){
		update(p[i].second);
		// printf("+ %d\n", p[i].second);

		for(int j = i + 1 ; j <= n ; j++){
			update(p[j].second);

			if(p[j].second == p[i].second || p[j].first == p[i].first || p[j].second < p[i].second) continue;

			int l = min(p[i].second, p[j].second);
			int r = max(p[i].second, p[j].second);

			int sum = rsq(l, r);

			if(sum == 4 && ver[p[i].first][p[j].second] && ver[p[j].first][p[i].second]){
				ans++;
			}
		}

		for(int j = i + 1 ; j <= n ; j++) update(p[j].second, -1);

		if(p[i + 1].first != p[i].first){
			memset(bit, 0, sizeof bit);
		}
	}

	printf("%d\n", ans);

	return 0;
}