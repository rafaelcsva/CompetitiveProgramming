#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
set<char>w;
ll cnt = 0LL;
int t;
string chf = "chef";
string s;
int j, ti, i, m, n;

int main (){
	ios::sync_with_stdio(false);
	
	m = chf.length();
	
	cin >> t;
	
	while(t--){
		cin >> s;
		n = s.length();
			
		cnt = 0LL;
	
		for(i = 0 ; i <= n - m ; i++){
			j = 0;
			ti = i;
			
			while(j < chf.length()){
				if(chf.find(s[ti]) != string::npos){
					w.insert(s[ti]);
				}
				
				ti++, j++;
			}
			
			if(w.size() == m){
				cnt++;
			}
			
			w.clear();
		}
		
		if(cnt > 0LL){
			cout << "lovely " << cnt << '\n';
		}else{
			cout << "normal\n";
		}
	}
	
	return 0;
}
