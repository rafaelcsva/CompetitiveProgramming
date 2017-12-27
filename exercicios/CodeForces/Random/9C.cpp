#include <bits/stdc++.h>

#define lli	long long int
using namespace std;

const int N = (1 << 14) - 1;

int main (){
	lli n;
	int ans = 0;

	cin >> n;
			
	for(int i = 1 ; i <= N ; i++){
		bitset<14>num(i);

		lli pot = 1;
		lli tmp = 0;

		for(int k = 0 ; k < num.size() ; k++){
			if(num[k]){
				tmp += pot;
			}

			pot = pot * 10;
		}

		if(tmp > n){
			ans = i - 1;
			break;
		}		
	}

	cout << ans << '\n';

	return 0;
}
