#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main (){
	string num = "";
	ll tm = 1LL;
	int k;
	
	ios::sync_with_stdio(false);
	
	cin >> k;
	int n = k;
	
	if(k > 18 * 2){
		cout << "-1\n";
		return 0;
	}
	
	int count = 0;
	
	for(int i = 0 ; i < n / 2 ; i++){
		count += 2;
		cout << "8";
	}
	
	if(n&1){
		count++;
		cout << "4";
	}
	cout << "\n";
	
	return 0;
}
