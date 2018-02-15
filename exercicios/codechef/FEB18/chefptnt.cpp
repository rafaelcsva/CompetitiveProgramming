#include <bits/stdc++.h>

using namespace std;

int main (){
	int t;
	
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--){
		int n, m, x, k;
		string s;
		
		cin >> n >> m >> x >> k;
		
		cin >> s;
		
		int cnt[2];
		cnt[0] = cnt[1] = 0;
		
		for(int i = 0 ; i < s.length() ; i++){
			if(s[i] == 'O'){
				cnt[1]++;
			}else{
				cnt[0]++;
			}
		}
		
		for(int i = 1 ; i <= m ; i++){
			int am = min(x, cnt[i % 2]);
			
			n -= am;
			cnt[i % 2] -= am;
		}
		
		if(n <= 0){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
	
	return 0;
}
