#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
const int N = 600, K = 10100;
vector<lli>courses[K];
vector<lli>comb;
map<lli, int>mp;

int cnt[N], sum[K];

int main (){
	int n;

	while(scanf("%d", &n)){
		if(n == 0)
			break;

		int ans = 0;

		for(int k = 0 ; k < n ; k++){
			for(int i = 0 ; i < 5 ; i++){
				lli c;

				scanf("%lld", &c);

				courses[k].push_back(c);
			}

			sort(courses[k].begin(), courses[k].end());

			lli tmp = 0;

			for(int i = 0 ; i < courses[k].size() ; i++){
				tmp = tmp * 1000 + courses[k][i];	
			}

			comb.push_back(tmp);
			mp[tmp]++;
		}

		for(int k = 0 ; k < n ; k++){
			ans = max(ans, mp[comb[k]]);
		}
	
		int kar = 0;

		for(int k = 0 ; k < n ; k++){
			if(mp[comb[k]] == ans)
				kar++;
		}

		printf("%d\n", kar);

		comb.clear();
		mp.clear();

		for(int i = 0 ; i < n ; i++){
			courses[i].clear();
		}

	}

	return 0;
}
