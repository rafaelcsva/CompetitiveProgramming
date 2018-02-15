#include <bits/stdc++.h>

using namespace std;

int grid[3][110];

int main (){
	int n;
	
	cin >> n;
	
	for(int i = 1 ; i <= 2 ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> grid[i][j];
		}
	}
	
	for(int i = 1 ; i <= 2 ; i++){
		for(int j = 1 ; j <= n ; j++){
			grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
		}
	}
	
	cout << grid[2][n] << '\n';
	
	return 0;
}
