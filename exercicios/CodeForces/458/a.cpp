#include <bits/stdc++.h>

using namespace std;

typedef long long int	ll;
bool isSquare(ll n){
	ll i = 0, f = n;
	
	while(i <= f){
		ll mid = (i + f) / 2;
		
		if(mid * mid == n){
			return true;
		}else if(mid * mid < n){
			i = mid + 1;
		}else{
			f = mid - 1;
		}
	}
	
	return false;
}

int main (){
	ll n;
	
	cin >> n;
	
	ll r = -1000010;
	
	for(int i = 0 ; i < n ; i++){
		ll a;
		
		cin >> a;
		
		if(a < 0){
			r = max(r, a);
			continue;
		}
		
		if(!isSquare(a)){
			r = max(r, a);
		}
	}
	
	cout << r << '\n';
	
	return 0;
	
}
