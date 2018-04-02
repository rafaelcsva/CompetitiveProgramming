#include <bits/stdc++.h>

using namespace std;

const int N = 30;
string s, u;
map<string, int>cnt;
int cnt1[N], cnt2[N];

bool isEqual(){
	for(int i = 0 ; i < N ; i++){
		if(cnt1[i] != cnt2[i]){
			return false;
		}
	}
	
	return true;
}

int main (){
	int t;
	
	cin >> t;
	
	while(t--){
		cin >> s;
		cin >> u;
		
		for(int i = 0 ; i < s.length() ; i++){
			cnt1[s[i] - 'a']++;
			cnt2[u[i] - 'a']++;
		}		
		
		string sub = u.substr(0, s.length());
		bool find = false;
		
		if(isEqual()){
			find = true;
			cnt[sub]++;
		}
		
		for(int i = s.length() ; i < u.length() ; i++){
			cnt2[sub[0] - 'a']--;

			sub.erase(0, 1);
			sub += u[i];

			cnt2[u[i] - 'a']++;
			
			if(isEqual()){
				find = true;
				
				cnt[sub]++;
			}			
		}
		
		if(find){
			int ans = 0;
			string r = "";
			for(map<string, int>::iterator it = cnt.begin() ; it != cnt.end() ; it++){
				if(ans < it->second){
					r = it->first;
					ans = it->second;
				}
			}
			
			cout << r << '\n';
		}else{
			cout << "-1\n";
		}
		
		cnt.clear();
		for(int i = 0; i < N ; i++){
			cnt1[i] = cnt2[i] = 0;
		}
	}
	
}
