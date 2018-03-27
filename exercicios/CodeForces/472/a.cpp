#include <bits/stdc++.h>

using namespace std;

string s;

int main (){
	int n;
	
	cin >> n;
	cin >> s;
	
	bool find = false;
	
	for(int i = 0 ; i < n ; i++){
		if(i + 1 < n && s[i] == s[i + 1] && s[i] != '?'){
			cout << "No\n";
			return 0;
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '?'){
			if(i == 0 || i == n - 1){
				find = true;
				break;
			}else{
				if(s[i + 1] == '?' || s[i + 1] == s[i - 1]){
					find = true;
					break;
				}
			}
		}
	}
	
	if(find){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	
	return 0;
}
