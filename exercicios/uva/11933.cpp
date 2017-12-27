#include <bits/stdc++.h>

#define lli	long long int
using namespace std;

int main (){
	lli n;

	while(cin >> n){
		if(n == 0LL)
			break;
	
		bitset<32>num(n);

		lli pot = 1;
		lli a = 0, b = 0;
		int op = 1;

		for(int i = 0 ; i < 32 ; i++){
			if(num[i] == 1){
				if(op){
					a += pot;
				}else{
					b += pot;
				}

				op = !op;
			}			

			pot = pot * 2;	
		}

		cout << a << ' ' << b << '\n';
	}

	return 0;
}
