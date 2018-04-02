#include <bits/stdc++.h>

using namespace std;

int main (){
	int m, n, t;
	char p;

	cin >> t;

	while(t--){
		cin >> p;
		cin >> m >> n;
		
		if(p == 'r' || p == 'Q'){
			cout << min(m, n);
		}	
		else if(p == 'k'){
			int m1 = m / 2;
			int m2 = m - m1;
			int q1 = n / 2;
			int q2 = n - q1;

			cout << m1 * q1 + m2 * q2;
		}else{
			int a = ceil(m / 2.0), b = ceil(n / 2.0);
			cout << a * b;
		}

		cout << '\n';
	}

	return 0;
}
