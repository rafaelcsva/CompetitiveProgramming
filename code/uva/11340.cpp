#include <bits/stdc++.h>

using namespace std;

int mark[1000];
int val[1000];

int main (){
	int n, K;
	
	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		long long int sum = 0;

		cin >> K;

		for(int k = 0 ; k < K ; k++){
			char v;
			int c;

			cin >> v >> c;
	
			val[v] = c;
			mark[v] = i;
		}		

		int m;
		string s;

		scanf("%d", &m);
		cin.ignore();
		for(int x = 0 ; x < m ; x++){
			getline(cin, s);

			for(int l = 0 ; l < s.length() ; l++){
				if(mark[s[l]] == i){
					sum += val[s[l]];
				}
			}
						
		}

		cout << sum / 100 << '.' ;

		if(sum % 100 < 10){
			cout << "0";
		}

		cout << sum % 100 << "$\n";
	}	

	return 0;
}
