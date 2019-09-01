#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e6 + 10);

typedef pair< ll, ll >	pii;
ll dp[N][16];
pii id[N];
vector< pii > fcon[N];
vector< ll > con[N];
vector< ll > ids;
vector< ll > fids;

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld %lld", &id[i].first, &id[i].second);

		ids.push_back(id[i].first);
	}

	sort(ids.begin(), ids.end());

	fids.push_back(ids[0]);

	for(int i = 1 ; i < n ; i++){
		if(ids[i] != ids[i - 1]){
			fids.push_back(ids[i]);
		}
	}

	for(int i = 0 ; i < n ; i++){
		int idx = lower_bound(fids.begin(), fids.end(), id[i].first) - fids.begin();

		con[idx].push_back(id[i].second);
	}

	for(int i = 0 ; i < n ; i++){
		sort(con[i].begin(), con[i].end());
	}

	for(int i = 0 ; i < fids.size() ; i++){
		vector< ll > els;

		int sz = con[i].size();

		els.push_back(con[i][0]);
		els.push_back(con[i][sz - 1]);

		if(sz > 1){
			if(sz > 2){
				els.push_back(con[i][1]);
			}

			if(sz > 3){
				els.push_back(con[i][sz - 2]);
			}

			for(int u = 0 ; u < els.size() ; u++){
				for(int o = 0 ; o < els.size() ; o++){
					if(u == o) continue;

					fcon[i].push_back({els[u], els[o]});

					// printf("%d %lld %lld\n", i, els[u], els[o]);
				}
			}
		}else{
			fcon[i].push_back({els[0], els[0]});
		}
	}

	ll ans = 0LL;

	for(int i = int(fids.size() - 2) ; i >= 0 ; i--){
		for(int t = 0 ; t < fcon[i].size() ; t++){
			for(int d = 0 ; d < fcon[i + 1].size() ; d++){
				dp[i][t] = max(dp[i][t], abs(fcon[i][t].second - fcon[i + 1][d].first) + dp[i + 1][d]);
			}
			
			if(i == 0){
				ans = max(ans, dp[i][t]);
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}