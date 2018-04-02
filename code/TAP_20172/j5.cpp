#include <bits/stdc++.h>

using namespace std;

int main (){
	string st;

	cin>>st;

	int s = 0;

	for(int i = 0 ; i < st.length() ; i++){
		s += st[i] - '0';
	}

	cout << s%3 << '\n';

	return 0;	
}
