#include <bits/stdc++.h>

using namespace std;

int main (){
	srand(time(NULL));
	int n = 100;
	int m = 50;

	cout << n << ' ' << m << '\n';

	for(int i = 0 ; i < n ; i++){
		cout << rand() % (40 + 1) << ' ';
	}
	cout << '\n';
	
	for(int i = 0 ; i < m ; i++){
		int op = rand() % 3 + 1;

		cout << op << ' ';
		if(op == 1 || op == 2){
			int l = rand() % (n + 1);

			cout << l << ' ' << rand() % (n + 1 - l) + l << '\n';
		}else if(op == 3){
			
			cout << rand() % (n + 1) << ' ' << rand() % (40 + 1) << '\n';
		}
	}

	return 0;
}
