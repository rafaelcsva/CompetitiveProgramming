#include <bits/stdc++.h>

using namespace std;

const int N = 600;
bool ver[N][N];

int solve(int i, int j, int n, int m){
	if(i >= n || j >= m)
		return 0;

	if(tab[i][j] == 0)
		return 0;

	int s = tab[i][j];
	int tmp = s;

	tab[i][j] = 0;

	if(i != n-1){
		if(j < m-1){
			s = max(s, s + solve(i, j + 1, n, m));
		}

		if(j > 0){
			s = max(s, s + solve(i, j - 1, n, m));
		}
	}else{
		 
	}

	s += solve(i + 1, j, n, m);

	tab[i][j] = tmp;
	return s;
}

int main (){
	int n, m;
	int tab[N][N];

	cin >> n >> m;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			cin >> tab[i][j];
	}

			

	return 0;
}
