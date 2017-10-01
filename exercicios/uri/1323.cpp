#include <bits/stdc++.h>

#define	ll	long long

using namespace std;

int main (){
	int n;
	
	while(cin>>n,n){

		ll s = 0;

		for(int i = 1 ; i <= n ; i++){
			 s += (1 + n-i)*(1 + n-i);
		}

		cout<<s<<'\n';
	}

	return 0;
}
