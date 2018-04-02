#include <bits/stdc++.h>

using namespace std;

int main (){
	int t = rand() % 100 + 1;
	
	cout << t << '\n';

	while(t--){
		int k = rand() % 10000 + 1;
		
		cout << k << '\n';
		
		for(int i = 0 ; i < 7 ; i ++){
			cout << rand() % 10000 << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
