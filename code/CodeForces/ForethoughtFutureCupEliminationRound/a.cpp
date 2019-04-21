#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;

	cin >> s;

	int qa = 0;

	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == 'a'){
			qa++;
		}
	}

	// cout << qa << endl;
	cout << min(int(s.length()), qa + qa - 1) << endl;

	return 0;
}