#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	cin >> s;

	int r = 0;

	for(int i = 0 ; i < s.length() ; i++){
		r += (s[i] != 'a');
	}

	if(r & 1){
		cout << ":(" << endl;
		
		return 0;
	}

	int take = r / 2;
	int stop = s.length();
	string p = "";

	for(int i = 0 ; i < s.length() ; i++){
		if(take && s[i] != 'a'){
			p.push_back(s[i]);
			take--;
		}else if(take == 0 && s[i] != 'a'){
			stop = i;

			break;
		}
	}

	int sz = s.length() - stop;

	if(sz != p.length()){
		cout << ":(" << endl;
		return 0;
	}

	for(int i = 0 ; i < p.length() ; i++){
		if(s[i + stop] != p[i]){
			cout << ":(" << endl;
			return 0;
		}
	}

	for(int i = 0 ; i < stop ; i++){
		cout << s[i];
	}

	cout << endl;

	return 0;
}