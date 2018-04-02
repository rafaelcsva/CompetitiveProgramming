#include <bits/stdc++.h>

using namespace std;

string week[10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int a[7];

int mod(int x){
	return (x + 7) % 7;
}

int main (){
	int t;
	
	cin >> t;
	
	while(t--){
		int k;
		
		cin >> k;
		
		for(int i = 0 ; i < 7 ; i++){
			cin >> a[i];
		}
		
		int i;
		
		for(i = 0 ; k > 0 ; i = (i + 1) % 7){
			k -= a[i];
		}
		
		cout << week[mod(i - 1)] << '\n';
	}
	
	return 0;
}
