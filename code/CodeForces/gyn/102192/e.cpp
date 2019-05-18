#include <bits/stdc++.h>

using namespace std;

string tab[3];

int addi[] = {0, 0, 1, 1};
int addj[] = {0, 1, 0, 1};

void rotate_clockwise(int add1, int add2){
	swap(tab[0 + add1][1 + add2], tab[1 + add1][1 + add2]);
	swap(tab[0 + add1][1 + add2], tab[1 + add1][0 + add2]);
	swap(tab[0 + add1][0 + add2], tab[0 + add1][1 + add2]);
}

void rotate_counter_clockwise(int add1, int add2){
	swap(tab[0 + add1][0 + add2], tab[1 + add1][0 + add2]);
	swap(tab[0 + add1][0 + add2], tab[1 + add1][1 + add2]);
	swap(tab[0 + add1][0 + add2], tab[0 + add1][1 + add2]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		int n;

		cin >> n;

		for(int i = 0 ; i < 3 ; i++){
			cin >> tab[i];
		}

		for(int i = 0 ; i < n ; i++){
			string op;

			cin >> op;

			int u = op[0] - '1';

			if(op[1] == 'C'){
				rotate_clockwise(addi[u], addj[u]);
			}else{
				rotate_counter_clockwise(addi[u], addj[u]);
			}
		}

		for(int i = 0 ; i < 3 ; i++){
			cout << tab[i] << endl;
		}
	}

	return 0;
}