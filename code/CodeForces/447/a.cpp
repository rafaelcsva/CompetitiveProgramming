#include <bits/stdc++.h>

using namespace std;

int main (){
	string s;
	int cnt = 0;

	cin >> s;

	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == 'Q'){
			for(int j = i + 1 ; j < s.length() ; j++){
				if(s[j] == 'A'){
					for(int k = j + 1 ; k < s.length() ; k++){
						if(s[k] == 'Q'){
							cnt++;
							
						}
					}
				}
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}
