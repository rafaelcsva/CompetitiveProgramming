#include <bits/stdc++.h>

using namespace std;

int main (){
	int n, a, b;
	
	cin >> n >> a >> b;
	
	n -= a;
	
	if(n > 0){
		cout << n % b << '\n';
	}else{
		cout << 0 << '\n';
	}
	
	return 0;
}
