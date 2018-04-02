#include <bits/stdc++.h>

using namespace std;

queue<int>car[2];

int main (){
	int c;

	cin >> c;

	while(c--){
		int l, m;

		cin >> l >> m;

		l = l * 100;

		string pos;

		for(int i = 0 ; i < m ; i++){
			int lc;
	
			cin >> lc >> pos;

			if(pos == "left"){
				car[0].push(lc);
			}else{
				car[1].push(lc);
			}
		}

		int side = 0;
		int travels = 0;
		
		while(!car[0].empty() || !car[1].empty()){
			int carry = 0;

			while(!car[side].empty() && carry + car[side].front() <= l){
				carry += car[side].front();				
				car[side].pop();
			}
			travels++;
			side = !side;
		}

		cout << travels << '\n';
	}

	return 0;
}
