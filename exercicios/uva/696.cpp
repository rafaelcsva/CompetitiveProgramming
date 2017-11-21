#include <bits/stdc++.h>

using namespace std;

int main (){
	int m, n;

	while(cin >> m >> n){
		if(m == 0){
			break;
		}
		int m1 = m / 2;
		int m2 = m - m1;
		int q1 = n / 2;
		int q2 = n - q1;
		int r = m1 * q1 + m2 * q2;

		if(m * n >= 4){
			r = max(r, 4);
		}
		if(n == 1 || m == 1)
			r = max(r, max(m, n));

		cout << r << " knights may be placed on a "<< m << " row " << n << " column board.\n";
	}

	return 0;
}
