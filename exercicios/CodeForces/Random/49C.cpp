#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	cin >> n;

	int a = 1, b = n;

	int op = 0;

	cout << a;
	a++;

	while(a <= b){
		if(op){
			cout << " " << a;
			a++;
		}else{
			cout << " " << b;
			b--;
		}
		op = (op + 1) % 2;
	}	

	cout << '\n';

	return 0;
}
