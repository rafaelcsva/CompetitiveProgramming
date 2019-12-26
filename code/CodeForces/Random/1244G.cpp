#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[300];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	cin >> s;

	k = min(k, 100 + (k & 1));

	// cout << "K: " << k << endl;

	for(int d = 0 ; d < k ;d++){
		string tmp = "";

		for(int i = 0 ; i < n ; i++){
			cnt[s[i]]++;
			cnt[s[(i + 1) % n]]++;
			cnt[s[(i - 1 + n) % n]]++;
			// cout << cnt['W'] << " " << cnt['B'] << endl;

			if(cnt['W'] > cnt['B']){
				tmp.push_back('W');
			}else{
				tmp.push_back('B');
			}

			cnt['W'] = cnt['B'] = 0;
		}
		s = tmp;
	}

	cout << s << endl;

	return 0;
}