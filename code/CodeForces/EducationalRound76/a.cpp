#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	cin >> t;

	while(t--){
		int n, x, a, b;

		cin >> n >> x >> a >> b;

		if(a > b){
			swap(a, b);
		}

		if(a - 1 >= x){
			a -= x;
			x = 0;
		}else{
			x -= (a - 1);
			a = 1;
		}

		if(n - b >= x){
			b += x;
			x = 0;
		}else{
			b = n;
		}

		cout << b - a << endl;
	}

	return 0;
}