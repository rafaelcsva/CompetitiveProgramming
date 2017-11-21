#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int value(string s){
	if(s[0] >= '2' && s[0] <= '9')
		return s[0] - '0';

	return 10;
}

int main (){
	int t;
	string s[N];

	cin >> t;
	
	for(int c = 1 ; c <= t ; c++){
		int top = 52 - 25 - 1;
		int ini = top + 1;

		for(int i = 0 ; i < 52 ; i++){
			cin >> s[i];
		}
		int y = 0;
		
		for(int i = 0 ; i < 3 ; i++){
			int x = value(s[top]);
			y += x;

			top -= (10 - x) + 1;
		}

		for(int i = top ; i < top + 25 ; i++){
			s[i + 1] = s[ini + i - top];
		}

		top += 25;

		cout << "Case " << c << ": " << s[y - 1] << '\n';
	}	

	return 0;
}
