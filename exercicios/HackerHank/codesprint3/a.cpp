#include <bits/stdc++.h>

using namespace std;

int main (){
	string s;
	
	cin>>s;
	
	int x = s[0] - '0';
	int y = s[2] - '0';
	
	if(s[1] == '+')
		cout<<x+y<<'\n';
	else
		cout<<x-y<<'\n';
		
	return 0;
}
