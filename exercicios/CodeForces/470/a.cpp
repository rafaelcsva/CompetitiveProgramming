#include <bits/stdc++.h>

using namespace std;

const int N = 510;
char p[N][N];
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, -1, 1};

int main (){
	int r, c;
	
	cin >> r >> c;
	
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> p[i][j];
		}
	}
	
	bool ok = true;

	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			if(p[i][j] == 'S'){
				for(int k = 0 ; k < 4 ; k++){
					int tx = i + vx[k], ty = j + vy[k];
					
					if(tx >= 0 && tx < r && ty >= 0 && ty < c){
						if(p[tx][ty] == 'W'){
							ok = false;
						}
						
						if(p[tx][ty] == '.')
							p[tx][ty] = 'D';
					}
				}
			}
		}
	}	
	
	if(ok){
		cout << "Yes\n";
		
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				cout << p[i][j];
			}
			cout << "\n";
		}
	}else{
		cout << "No\n";
	}
	
	return 0;
}
