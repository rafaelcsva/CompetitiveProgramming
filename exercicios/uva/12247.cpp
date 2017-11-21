#include <bits/stdc++.h>

using namespace std;
int used[60];

int main(){
	int deck[5];
	

	while(1){
		for(int i = 0 ; i < 5; i ++){
			cin >> deck[i];
			used[deck[i]] = 1;
		}
	
		if(deck[0] == 0)
			break;

		int mark[5];
		int cnt = 0;

		for(int i = 0 ; i < 5 ; i++)
			mark[i] = 0;

		sort(deck, deck + 3);
		sort(deck + 3, deck + 5); 

		for(int i = 0 ; i < 3 ; i ++){
			bool ver = true;

			for(int j = 3 ; j < 5 ; j++){
				if(deck[i] > deck[j] && !mark[j]){
					cnt++;
					mark[j] = 1;
					break;
				}
			}
		}

		if(cnt > 1){
			cout << "-1\n";
		}else if(cnt == 1){
			int m;

			if(deck[1] > deck[3])
				m = deck[2];
			else
				m = deck[1];

			while(used[m])
				m++;

			if(m <= 52)
				cout << m << '\n';
			else
				cout << "-1\n";
		}else{
			int m = 1;

			while(used[m])
				m++;

			cout << m << '\n';
		}

		for(int i = 0 ; i <= 52 ; i++)
			used[i] = 0;
	}

	return 0;
}
