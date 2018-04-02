#include <bits/stdc++.h>

using namespace std;

int mark[12];

bool isNot(string s, char c){
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == c){
			return false;
		}
	}

	return true;
}

int main (){
	int t;

	cin >> t;

	while(t--){
		string sa, sb, r;

		for(int i = 0 ; i < 3 ; i++){
			cin >> sa >> sb >> r;

			int x, m;

			if(r == "even"){
				x = 1;	
				m = 1;			
			}else if(r == "up"){
				x = 3;
				m = 2;
			}else{
				x = 2;
				m = 3;
			}

			for(int j = 0 ; j < sa.length() ; j++){
				int p = sa[j] - 'A';
				int h = sb[j] - 'A';
		
				if(mark[p] == 0 || x == 1){
					mark[p] = x;
				}else if(mark[p] != 1){
					if(mark[p] != x){
						mark[p] = 1;
					}
				}
				//cout << h << ' ' << m << '\n';
				if(mark[h] == 0 || m == 1){
					mark[h] = m;
				}else if(mark[h] != 1){
					if(mark[h] != m){
						mark[h] = 1;
					}
				}
			}

			if(x != 1){
				for(int i = 0 ; i < 12 ; i++){
					char coin = i + 'A';

					if(isNot(sa, coin) && isNot(sb, coin)){
						mark[i] = 1;
					}
				}
			}
		}

		int counterfeit;

		for(int i = 0 ; i < 12 ; i++){
			if(mark[i] > 1){
				counterfeit = i;
				break;
			}		
		}			
		char c = counterfeit + 'A';
		string w = mark[counterfeit] == 2 ? "light.\n" : "heavy.\n";

		cout << c << " is the counterfeit coin and it is " << w;
	
		for(int i = 0 ; i < 12 ; i++)
			mark[i] = 0;		
	}

	return 0;
}
