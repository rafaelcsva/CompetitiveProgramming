#include <bits/stdc++.h>

using namespace std;

string s;
int t, n, test = 1;

int main (){
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--){
		
		cin >> n;
		cin >> s;
		
		int step = 0;

		int ans = 0;
		
		while(step < n){
			if(s[step] == '.'){
				step += 3;
				ans++;
			}else{
				step++;
			}
		}
		
		cout << "Case " << test++ << ": " << ans << '\n';
	}
	
	return 0;
}
