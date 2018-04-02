#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

bool verify(int n, int k, int d){
	int tmp = 1;
	int i = 0;
	
	while(i < d && tmp < n){
		tmp = tmp * k;
		i++;
	}
	
	return tmp >= n;
}
vector<int>numbers[N];

int digts[N];

int main (){
	int n, K, d;
	
	ios::sync_with_stdio(false);
	
	cin >> n >> K >> d;
	
	if(verify(n, K, d)){
		for(int k = 0 ; k < n ; k++){
			for(int i = 0 ; i < d ; i++){
				numbers[k].push_back(digts[i] + 1);
					
				if(i == d - 1){
					digts[i]++;
				}
			}
			for(int i = d - 1 ; i >= 0 ; i--){
			//	cout << digts[i] ;
				if(digts[i + 1] == K){
					digts[i]++;
					digts[i + 1] = 0;
				}
				
			//	cout << " -> " << i << ' ' << digts[i] << '\n';
			}
		}
		
		for(int i = 0 ; i < d ; i++){
			for(int j = 0 ; j < n ; j++){
				cout << numbers[j][i] << ' ';
			}
			cout << '\n';
		}
	}else{
		cout << "-1\n";
	}
}
