#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	ll a, b, c;

	cin >> a >> b >> c;

	if(a == b){
		cout << 2LL * c + a * 2LL << endl;
	}else{
		cout << 2LL * c + min(a, b) * 2LL + 1LL << endl;
	}

	return 0;
}