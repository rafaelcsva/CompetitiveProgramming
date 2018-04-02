#include <bits/stdc++.h>

using namespace std;

const int N = 100;
char tab[N][N];
int n, m;

bool verify(int i, int j){
	int k = i + 1;
	bool ok = true;
	
	for(; k < n && ok ; k++){
		if(tab[k][j] == '#'){
			for(int t = 0 ; t < m ; t++){
				if(tab[k][t] != tab[i][t]){
					ok = false;
					break;
				}
			}
		}
	}
	
	return ok;
}

int main (){
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> tab[i][j];
		}
	}
	
	bool ok = true;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(tab[i][j] == '#'){
				ok &= verify(i, j);
			}
		}
	}
	
	if(ok){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}
