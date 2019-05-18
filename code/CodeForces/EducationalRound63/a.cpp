#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int n;

	cin >> n;
	cin >> s;

	int j = 0;
	
	bool ok = false;

	for(int i = 0 ; i < int(s.length()) - 1 ; i++){
		if(s[i] > s[i + 1]){
			swap(s[i], s[i + 1]);
			j = i;
			ok = true;
			break;
		}
	}

	if(ok){
		cout << "YES" << endl;
		cout << (j + 1) << " " << (j + 2) << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}