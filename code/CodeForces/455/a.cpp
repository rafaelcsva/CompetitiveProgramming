#include <bits/stdc++.h>

using namespace std;

int main (){
	string f, l;

	cin >> f >> l;

	string m = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	for(int i = 1 ; i <= f.length() ; i++){
		for(int j = 1 ; j <= l.length() ; j++){
			string c = f.substr(0, i) + l.substr(0, j);

			m = min(c, m);

		}
	}	

	cout << m << '\n';

	return 0;
}
