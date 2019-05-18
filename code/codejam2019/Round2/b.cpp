#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
typedef pair< ll, ll > pll;
vector< pll > tr;
const int N = 100;
pll p[N];

bool works(pll r, int n){
	ll last = -1LL;

	for(int i = 0 ; i < n ; i++){
		ll val = p[i].first * r.first + p[i].second * r.second;

		if(last >= val){
			return false;
		}

		last = val;
	}

	return true;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int test = 1 ; test <= t ; test++){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%lld %lld", &p[i].first, &p[i].second);
		}

		tr.push_back({1LL, 1LL});

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if((p[i].first >= p[j].first && p[i].second >= p[j].second) || (p[i].first <= p[j].first && p[i].second <= p[j].second)){
					continue;
				}

				if(p[i].first > p[j].first){
					if(i > j){
						tr.push_back({p[j].second - p[i].second + 1LL, p[i].first - p[j].first});
					}else{
						tr.push_back({p[j].second - p[i].second , p[i].first - p[j].first + 1LL});
					}
				}else if(p[i].second > p[j].second){
					if(i > j){
						tr.push_back({p[i].second - p[j].second, p[j].first - p[i].first + 1LL});
					}else{
						tr.push_back({p[i].second - p[j].second + 1LL, p[j].first - p[i].first});
					}
				}
			}
		}

		pll resp = {-1, -1};

		for(int i = 0 ; i < tr.size() ; i++){
			if(works(tr[i], n)){
				if(resp.first == -1 || resp > tr[i]){
					resp = tr[i];
				}
			}
		}

		printf("Case #%d: ", test);

		if(resp.first == -1){
			printf("IMPOSSIBLE\n");
		}else{
			printf("%lld %lld\n", resp.first, resp.second);
		}

		tr.clear();
	}

	return 0;
}