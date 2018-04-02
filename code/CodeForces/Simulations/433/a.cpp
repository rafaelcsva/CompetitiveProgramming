#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;

	cin>>n;	

	for(int i = n-1; i >= 1 ; i--){
		for(int j = i+1 ; j <= n ;j ++){
			if(i+j == n){
				if(__gcd(i, j) == 1){
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
			}
		}
	}

	return 0;
}
