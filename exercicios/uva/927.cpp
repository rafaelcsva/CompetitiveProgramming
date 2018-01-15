#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
const int N = (int) 1e6;
lli c[N];

int main (){
	int t;

	ios::sync_with_stdio(false);

	cin >> t;

	while(t--){
		int g, d, k;

		cin >> g;

		for(int i = 0 ; i <= g ; i++){
			cin >> c[i];
		}
		
		cin >> d >> k;

		lli n = 1;

		while(n * d + d * n * n < 2 * k){
			n++;
		}

		lli tmp = 1;
		lli sum = 0;

		for(int i = 0 ; i <= g ; i++){
			sum += tmp * c[i];

			tmp = tmp * n;			
		}

		cout << sum << '\n';
	}

	return 0;
}
