#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main (){
	ll n, m;
	
	cin >> n >> m;
	if(n == 1LL && m == 1LL){
		cout << "1\n";
	}
	else if(n == 2LL || m == 2LL){
		cout << "0\n";
	}else if(n == 1){
		cout << m - 2LL << '\n';
	}else if(m == 1){
		cout << n - 2LL << '\n';
	}else{
		cout << (n - 2LL) * (m - 2LL) << '\n';
	}
	
	return 0;
}
