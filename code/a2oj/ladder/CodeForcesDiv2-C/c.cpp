#include <bits/stdc++.h>

using namespace std;

const int M = 110, S = 1000;

string dp[M][S];

bool cob(int l, int s){
	return l*9 >= s;

}

int main (){
	int m, s;

	cin>>m>>s;

	int soma = 0;

	int pos = 1;
	char n[M];

	for(int i = 0; i < m ; i++){
		for(int d = 0 ; d < 10 ; d++){
			if(i == 0 && d == 0 && m != 1)
				continue;

			if(s-soma-d >= 0 && cob(m-(i+1), s-d-soma)){
				n[i] = d + '0';
			
				soma+=d;
				break;
			}

		}
	}
	if(soma != s||s == 0 && m != 1){
		cout<<"-1 -1\n";
	}
	else{
		for(int i = 0 ; i < m ; i++)
			cout<<n[i];

		cout<<' ';

		soma = 0;
		for(int i = 0; i < m ; i++){
			for(int d = 9 ; d >= 0 ; d--){
				if(i == 0 && d == 0)
					continue;

				if(s-soma-d >= 0 && cob(m-(i+1), s-d-soma)){
					n[i] = d + '0';
				
					soma+=d;
					break;
				}

			}
		}

		for(int i = 0 ; i < m ; i++)
			cout<<n[i];

		cout<<'\n';
	}
	
	return 0;
}
