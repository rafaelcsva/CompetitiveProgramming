#include <bits/stdc++.h>

using namespace std;

map< int, vector< int > > mp;
map< int, int > cnt;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);

			mp[a[i]].push_back(i);
		}

		for(int i = 0 ; i < m ; i++){
			scanf("%d", &b[i]);

			cnt[b[i]]++;
		}
	}

	return 0;
}