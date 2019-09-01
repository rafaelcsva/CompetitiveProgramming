#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
vector< int > v1;
const int N = int(1e5 + 10);
int pref[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		string s;

		cin >> s;

		for(int i = 0 ; i < s.length() ; i++){
			if(s[i] == '1'){
				pref[i + 1] = 1LL;
			}

			pref[i + 1] += pref[i];
		}

		ll tot = 0LL;

		for(int j = 1 ; j * j + j <= s.length() ; j++){
			int len = j * j + j;

			for(int k = 0 ; k <= s.length() - len ; k++){
				if(pref[k + len] - pref[k] == j){
					tot++;
				}
			}
		}

		printf("%lld\n", tot);

		memset(pref, 0LL, sizeof pref);
	}

	return 0;
}