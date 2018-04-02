#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5, M = 11;
int used[M][N], k;
bool dp[M][N];
int cont[M];
int sum;

int main (){
	int t;

	cin >> t;

	for(k = 1 ; k <= t ; k++){
		int n;
		sum = 0;

		cin >> n;

		for(int i = 0 ; i < M ; i++){
			cont[i] = 0;
		}
		
		int bagA = 0, bagB = 0;

		bool ver = true;

		for(int i = 0 ; i < n ; i++){
			int a;

			cin >> a;
	
			if(abs(bagA + a - bagB) <= 5){
				bagA += a;
			}else{
				bagB += a;
			}

			if(abs(bagA - bagB) > 5)
				ver = false;
		}

		if(ver){
			cout << "Feliz Natal!\n";
		}else{
			cout << "Ho Ho Ho!\n";
		}

	}

	return 0;
}
