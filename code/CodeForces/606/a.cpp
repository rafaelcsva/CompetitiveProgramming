#include <bits/stdc++.h>

using namespace std;

vector< int > ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		string s;

		cin >> s;

		int n = s.length();

		for(int i = 0 ; i <= n - 5 ; i++){
			if(s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e'){
				s[i + 2] = '?';
				ans.push_back(i + 3);
			}
		}

		for(int i = 0 ; i <= n - 2 ; i++){
			if(s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'){
				s[i + 1] = '?';
				ans.push_back(i + 2);
			}
		}

		for(int i = 0 ; i <= n - 2 ; i++){
			if(s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e'){
				s[i + 1] = '?';
				ans.push_back(i + 2);
			}
		}

		// cout << s << "\n";

		cout << ans.size() << '\n';

		for(int u: ans){
			cout << u << " ";
		}

		cout << "\n";

		ans.clear();
	}

	return 0;
}