#include <bits/stdc++.h>

using namespace std;

typedef struct{
	string name;
	int l, r;
}Database;

const int N = (int) 1e5;
Database cars[N];

int main (){
	int t;
	bool ver = false;
	
	ios::sync_with_stdio(false);

	cin >> t;

	while(t--){
		int d;

		if(ver)
			cout << '\n';
			
		ver = true;
		
		cin >> d;

		int tam = 0;

		for(tam = 0 ; tam < d ; tam++){
			cin >> cars[tam].name >> cars[tam].l >> cars[tam].r;
		}
		
		int q;

		cin >> q;

		while(q--){
			int p;

			cin >> p;

			string resp = "UNDETERMINED";
			for(int i = 0; i < tam ; i++){
				if(cars[i].l <= p && cars[i].r >= p){
					if(resp != "UNDETERMINED"){
						resp = "UNDETERMINED";
						break;
					}else{
						resp = cars[i].name;
					}
				}
			}
			
			cout << resp << '\n';
		}

	}

	return 0;
}
