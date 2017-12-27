#include <bits/stdc++.h>

using namespace std;

int main (){
	string s;

	while(cin >> s){
		if(s == "#"){
			break;
		}

		bool next = next_permutation(s.begin(), s.end());

		if(next){
			cout << s << '\n';
		}else{
			cout << "No Successor\n";
		}
	}

	return 0;
}
