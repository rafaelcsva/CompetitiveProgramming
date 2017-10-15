#include <bits/stdc++.h>

#define	ll	long long

using namespace std;

int main (){
	int q;
	
	cin>>q;

	while(q--){
		ll n;

		cin>>n;

		ll q = n / 2;
		ll r = n % 2;
		int resp = 0;
		
		if(r != 0){
			if(q >= 4){
				q -= 4;
				resp++;
			}
			else{
				resp = -1;
			}
		}

		if(resp != -1 && q % 2 != 0){
			if(q >= 3){
				q -= 3;
				resp++;
			}
		}

		if(resp == -1 || resp + q / 2 <= 0){
			resp = -1;
		}else{
			resp = resp + q/2;
		}

		cout<<resp<<endl;

	}

	return 0;
}
