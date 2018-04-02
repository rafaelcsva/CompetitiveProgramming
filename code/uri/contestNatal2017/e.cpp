#include <bits/stdc++.h>

using namespace std;

int main (){
	int sum = 0;
	string rens[9] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen" ,"Rudolph"};

	for(int i = 0 ; i < 9 ; i++){
		int a;

		cin >> a;

		sum += a;
	}

	cout << rens[(sum - 1) % 9] << '\n';

	return 0;
}
