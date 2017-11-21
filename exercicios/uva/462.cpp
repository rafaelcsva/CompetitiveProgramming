#include <bits/stdc++.h>

using namespace std;

const int N = 20;
string s[N];

void loop(char c, int cond, int &sum){

	for(int i = 0 ; i < 13 ; i++){
		if(s[i][0] == c){
			int ver = 0;
			for(int j = 0 ; j < 13 ; j++){
				if(j == i)
					continue;

				if(s[j][1] == s[i][1]){
					ver++;
				}
			}

			if(ver <= cond)
				sum--;
		}
	}
}

int IsStopped(char c){

	for(int i = 0 ; i < 13 ; i++){
		if(s[i][1] == c && s[i][0] == 'A'){
			return 1;
		}
	}

	for(int i = 0 ; i < 13 ; i++){
		if(s[i][0] == 'K' && s[i][1] == c){
			for(int j = 0 ; j < 13 ; j++){
				if(i == j)
					continue;

				if(s[j][1] == c){
					return 1;
				}
			}
		}
	}

	for(int i = 0 ; i < 13 ; i++){
		if(s[i][0] == 'Q' && s[i][1] == c){
			int cnt = 0;
			for(int j = 0 ; j < 13 ; j++){
				if(i == j)
					continue;

				if(s[j][1] == c){
					cnt++;
				}
			}

			if(cnt >= 2)
				return 1;
		}
	}

	return 0;
}

int main (){
	char suits[4] = {'S', 'H', 'D', 'C'};
	map<char,int>tb;
	map<char, int>cont;
	
	tb['A'] = 4;
	tb['K'] = 3;
	tb['Q'] = 2;
	tb['J'] = 1;
 
	while(cin >> s[0]){
		int sum = 0;
		int stpd = 0;
		char most = s[0][1];
		int partial = 0;

		sum += tb[s[0][0]];
		cont[most]++;

		for(int i = 1 ; i < 13 ; i++){
			cin >> s[i];		

			sum += tb[s[i][0]];
			cont[s[i][1]]++;

			if(cont[most] < cont[s[i][1]])
				most = s[i][1];
			else if(cont[most] == cont[s[i][1]])	
				most = max(most, s[i][1]);
		}

		loop('K', 0, sum);
		loop('Q', 1, sum);
		loop('J', 2, sum);

		for(int i = 0 ; i < 4 ; i++){
			if(cont[suits[i]] == 2)
				partial++;
			if(cont[suits[i]] == 1)
				partial += 2;
			if(cont[suits[i]] == 0)
				partial += 2;

			stpd += IsStopped(suits[i]); 
		}

		if(sum + partial < 14){
			cout << "PASS\n";
		}else if(sum >= 16 && stpd == 4){
			cout << "BID NO-TRUMP\n";
		}else{
			cout << "BID " << most << '\n';
		}	

		cont.clear();
	}

	return 0;
}
