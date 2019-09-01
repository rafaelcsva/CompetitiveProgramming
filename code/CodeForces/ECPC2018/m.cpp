#include <bits/stdc++.h>

using namespace std;

vector< int > vals;
const int N = int(3e5);
int bit[N];

int LSOne(int x){
	return x & (-x);
}

int query(int x){
	int sum = 0;

	while(x != 0){
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
	return query(r) - query(l - 1);
}

class Seg{
public:
	int x, r, q;
};

Seg seg[N];

bool compar(Seg a, Seg b){
	if(a.x + a.r > b.x + b.r){
		return true;
	}else if(a.x + a.r < b.x + b.r){
		return false;
	}else{
		return a.x - a.q < b.x - b.q;
	}
}

int ans[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < n ; i++){
			int xi, ri, qi;

			scanf("%d %d %d", &xi, &ri, &qi);

			seg[i] = {xi, ri, qi};

			vals.push_back(xi - qi);
			vals.push_back(xi + ri);
		}

		sort(seg, seg + n, compar);

		for(int i = 0 ; i < m ; i++){
			scanf("%d %d", &qu[i].first, &qu[i].second);

			vals.push_back(qu[i].first);
			vals.push_back(qu[i].first - qu[i].second);
		}

		sort(vals.begin(), vals.end());

		int pt = 0;

		for(int i = m - 1 ; i >= 0 ; i--){
			while(pt < n && seg[pt].x + seg[pt].r >= qu[i].first){
				int idx = lower_bound(vals.begin(), vals.end(), seg[pt])
				pt++;
			}
		}

		vals.clear();
	}

	return 0;
}