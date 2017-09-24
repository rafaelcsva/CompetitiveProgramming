#include <bits/stdc++.h>

using namespace std;

int c[200];

int main (){
	int n, x;
	
	cin>>n>>x;

	int min = 0;

	for(int i = 0 ; i < n ; i++){
		int a;
		cin>>a;

		c[a] = 1;
		
	}

	int op = 0;

	for(int i = 0 ; i < x ; i++){
		if(!c[i])
			op++;
	}

	if(c[x])
		op++;

	cout<<op<<'\n';

	return 0;
}
