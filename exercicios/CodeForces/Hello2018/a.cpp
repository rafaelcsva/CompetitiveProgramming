#include <bits/stdc++.h>

using namespace std;

int main (){
	ios::sync_with_stdio(false);
	int n,m;

	cin >> n >> m;

	int tmp = 1;

	for(int i = 1 ; i <= n && tmp <= m ; i++, tmp = tmp * 2){

	}

	cout << m % tmp << '\n';
	return 0;
}
