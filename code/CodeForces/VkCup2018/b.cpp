#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
int x[N];
int gcd = 0;
set<int>st;

int main (){
	int n;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> x[i];
	}	
	
	sort(x, x + n);
	
	for(int i = 1 ; i < n ; i++){
		gcd = __gcd(x[i] - x[i - 1], gcd);
		st.insert(x[i] - x[i - 1]);	
	}
	
	if(st.size() == 1){
		cout << "0\n";
	}else{
		int tot = 0;
		
		for(int i = 1 ; i < n ; i++){
			tot += (x[i] - x[i - 1]) / gcd - 1;
		} 
		
		cout << tot << '\n';
	}
	
	return 0;
}
