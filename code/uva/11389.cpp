#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e3;
int m[N], e[N];

int main (){
	int n, d, r;
	
	ios::sync_with_stdio(false);
	
	while(cin >> n >> d >> r){
		if(!n && !d && !r){
			break;
		}
		 
		for(int i = 0 ; i < n ; i++){
			cin >> m[i];
		}
		
		for(int i = 0 ; i < n ; i++){
			cin >> e[i];
		}
		
		sort(m, m + n, greater<int>());
		sort(e, e + n);
		
		int amount = 0;
		
		for(int i = 0 ; i < n ; i++){
			int sum = e[i] + m[i];
			
			if(sum > d){
				amount += (sum - d) * r;
			}
		}
		
		cout << amount << '\n';
	}


	return 0;
}
