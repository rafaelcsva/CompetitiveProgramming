#include <bits/stdc++.h>

using namespace std;

int main (){
	int n, m, t;

	cin >> t;

	while(t--){
		cin >> n >> m;

		int bag = 0;
		int travels = 1;

		for(int i = 0 ; i < n ; i++){
			int p;
	
			cin >> p;
	
			if(bag + p > m){
				travels++;
				bag = p;	
			}else{
				bag += p;
			}
		}

		cout << travels << '\n';
	}

	return 0;
}
