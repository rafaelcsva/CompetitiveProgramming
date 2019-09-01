#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	cin >> t;

	while(t--){
		int a, b, n;

		cin >> a >> b >> n;

		if((n + 1) % 3 == 1){
			cout << a << endl;
		}else if((n + 1) % 3 == 2){
			cout << b << endl;
		}else{
			cout << (a ^ b) << endl;
		}
	}

	return 0;
}