#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		string a, b;

		cin >> a >> b;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int i = 0;
		int j = 0;
		int ans = 0;

		while(a.length() < b.length()){
			a.push_back('0');
		}

		while(b.length() < a.length()){
			b.push_back('0');
		}

		while(i < a.length() && j < b.length()){
			int runned = 0;

			if(b[j] == '0'){
				j++, i++;
				continue;
			}

			if(b[j] == '1' && a[i] == '1'){
				i++, j++;

				while(i < a.length() && j < b.length() && a[i] != b[j]){
					runned++;
					i++, j++;
				}

				ans = max(ans, runned + 2);
			}else{
				ans = max(ans, 1);
				i++, j++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}