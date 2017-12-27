#include <bits/stdc++.h>

using namespace std;

string removeChar(string s, char c){
	string r = "";

	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] != c)
			r += s[i];
	}

	return r;
}

int sumNextGames(string game, int k, int n){
	int sum = 0;
	int carry = -1;
	int str = 0;

	for(int i = 0 ; i < n && (i + k) < game.length() ; i++){
		if(game[i + k] == 'X'){
			sum += 10;
		}else{
			if(carry != -1){
				if(game[i + k]  == '/'){
					sum += 10;
				}else{
					sum += carry + game[i + k] - '0';
				}

				carry = -1;
			}else{
				carry = game[i + k] - '0';
			}
		}
	}

	if(carry != -1)
		sum += carry;

	return sum;
}

int main (){
	string game;

	while(getline(cin, game)){
		if(game == "Game Over"){
			break;
		}

		game = removeChar(game, ' ');
		//cout << game << '\n';
		int n = game.length();
		int p = 0;
		int g = 1;
		int carry = -1;

		for(int i = 0 ; i < n ; i++){
			int tmp = p;
		//	cout << i << " points: ";
			if(game[i] == 'X'){
				if(g < 10){
					p += sumNextGames(game, i + 1, 2);
				//	cout << sumNextGames(game, i + 1, 2) << ' ';
				}

				p += 10;

				g++;
			}else{
				if(carry != -1){
					if(game[i] == '/'){
						if(g < 10){
							p += sumNextGames(game, i + 1, 1);
				
						}
						p += 10;	
					}else{
						p += carry + game[i] - '0';
					}

					carry = -1;
					g++;
				}else{
					carry = game[i] - '0';
				}
			}
			//cout << p - tmp << '\n';
		}

		if(carry != -1)
			p += carry;

		cout << p << '\n';
	}

	return 0;
}
