#include <bits/stdc++.h>

using namespace std;

int main (){
	string s;
	int frq[100];

	cin>>s;

	for(int i = 0 ; i < 100 ; i++)
		frq[i] = 0;

	int complexity = 0;

	for(int i = 0 ; i < s.length() ; i++){
		if(!frq[s[i] - 'a'])
			complexity++;

		frq[s[i] - 'a']++;
	}

	sort(frq, frq+100);

	int erases = 0;

	for(int i = 0 ; i < 100&&complexity > 2 ; i++){
		if(frq[i] == 0)
			continue;

		erases += frq[i];
		complexity--;

	}
	
	printf("%d\n", erases);			
}
