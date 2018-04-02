#include <bits/stdc++.h>

#define	ll	long long

using namespace std;

int main (){
	ll n, k;

	cin>>n>>k;

	int min, max;

	if(k == 0){
		cout<<"0 0\n";
		return 0;
	}
	if(k <= n-1){
		min = 1;
	}else{
		min = 0;
	}

	if(2*k < n){
		max = k+1;		
	}else{
		max = n-k;
	}

	cout<<min<<' '<<max<<'\n';
	
	return 0;
}
