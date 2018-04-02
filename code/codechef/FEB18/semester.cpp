#include <bits/stdc++.h>

using namespace std;

typedef long long 	ll;
string week[10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
ll a[10];

int main (){
	int t;
	
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--){
		ll k;
		
		cin >> k;
		
		ll sum = 0LL;
		
		for(int i = 0 ; i < 7 ; i++){
			cin >> a[i];
			
			sum += a[i];
		}
		
		ll rst = k % sum;
		
		if(rst == 0LL){
			for(int i = 6 ; i >= 0 ; i--){
				if(a[i] != 0LL){
					cout << week[i] << '\n';
					break;
				}
			}
		}else{
			for(int i = 0 ; i < 7 ; i++){
				if(rst <= 0LL){
					cout << week[i - 1] << '\n';
					break;
				}
				
				rst -= a[i];
			}
		}
	}
	
	return 0;
}
