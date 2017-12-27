#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int mark[N];
int q = 3;

bool IsOne(){
	int cnt = 0;
	int cnt0 = 0, cntm1 = 0;
	
	for(int i = 0 ; i < 26 ; i++){
		if(mark[i] == 1){
			cnt++;
		}

		if(mark[i] == -1){
			cntm1++;
		}
	}
	
	if(cntm1 == 1){
		for(int i = 0 ; i < 26 ; i++){
			if(mark[i] == -1){
				mark[i] = 1;
				return true;
			}
		}
	}

	return cnt == 1;
}

int main (){
	for(int i = 0 ; i < 29 ; i++){
		mark[i] = -1;
	}

	int n;
	string w;

	cin >> n;

	int save = 0;
	bool isOne = false;

	for(int i = 0 ; i < n ; i++){
		char op;

		cin >> op;

		cin >> w;

		if(op == '.'){
			for(int i = 0 ; i < w.length() ; i++){
				int tmp = w[i] - 'a';
				mark[tmp] = 0;
			}

			isOne = IsOne();

		}else if(op == '!'){
			bool flag = false;

			int cnt = 0;
			
			isOne = IsOne();
			
			if(isOne){
				//cout << "+1\n";
				save++;
			}

			for(int i = 0 ; i < w.length() ; i++){
				int tmp = w[i] - 'a';
			
				if(mark[tmp] == -1){
					if(!isOne){
						mark[tmp] = q;
					}else{
						mark[tmp] = 0;
					}
				}

				if(mark[tmp] == 1){
					mark[tmp] = q;
				}
			}

			for(int i = 0 ; i < 26 ; i++){
				if(mark[i] == q){
					mark[i] = 1;
				}else{
					mark[i] = 0;
				}
			}
		}else{
			int tmp = w[0] - 'a';
			bool flag = false;
			
			isOne = IsOne();

			if(isOne && i != n - 1){
				//cout << "+1\n";
				save++;
			}

			mark[tmp] = 0;	
		}

		q++;
	}

	cout << save << '\n';
	return 0;
}
