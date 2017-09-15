#include <bits/stdc++.h>

using namespace std;

int main (){
	string s;

	getline(cin,s);

	int a = s[0] - '0';
	int b = s[4] - '0';

	s[8]-'0' == a+b ? cout<<"YES\n" : cout<<"NO\n" ;

	return 0; 
}
