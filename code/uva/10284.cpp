#include <bits/stdc++.h>

using namespace std;

enum color{white, black, red};

void markHorizontal(int lin, int col, int tab[][8]){

	for(int i = lin + 1 ; i < 8 ; i++){
		if(tab[i][col] == red)
			break;

		tab[i][col] = black;
	}

	for(int i = lin - 1 ; i >= 0 ; i--){
		if(tab[i][col] == red)
			break;

		tab[i][col] = black;
	}	

	for(int j = col + 1 ; j < 8 ; j++){
		if(tab[lin][j] == red)
			break;

		tab[lin][j] = black;
	}

	for(int j = col - 1; j >= 0 ; j--){
		if(tab[lin][j] == red)
			break;
			
		tab[lin][j] = black;
	}
}

void markDiagonal(int lin, int col, int tab[][8]){

	for(int i = lin + 1, j = col + 1; i < 8 && j < 8 ; i++, j++){
		if(tab[i][j] == red)
			break;

		tab[i][j] = black;
	}

	for(int i = lin - 1, j = col - 1; i >= 0 && j >= 0 ; i--, j--){
		if(tab[i][j] == red)
			break;

		tab[i][j] = black;
	}

	for(int i = lin + 1, j = col - 1; i < 8 && j >= 0 ; i++, j--){
		if(tab[i][j] == red)
			break;

		tab[i][j] = black;
	}

	for(int i = lin - 1, j = col + 1; i >= 0 && j < 8 ; i--, j++){
		if(tab[i][j] == red)
			break;

		tab[i][j] = black;
	}
}

void markCustomized(int lin, int col, int tab[][8] ,int vetx[], int vety[], int p){

	for(int i = 0 ; i < p ; i++){
		int x = lin + vetx[i];
		int y = col + vety[i];

		if(x >= 0 && x < 8 && y >= 0 && y < 8){
			if(tab[x][y] == white)
				tab[x][y] = 1;
		}
	}
}

int main (){
	string s;
	int tab[8][8];
	char mp[8][8];
	int bx[8] = {1, -1, 1, -1, 2, 2, -2, -2};
	int by[8] = {2, 2, -2, -2, 1, -1, 1, -1};
	int kx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
	int ky[8] = {0, 1, 0, -1, 1, -1, -1, 1};
	int pBx[2] = {1, 1};
	int pBy[2] = {-1, 1};
	int pWx[2] = {-1, -1};
	int pWy[2] = {-1, 1};

	while(cin >> s){
		for(int i = 0 ; i < 8; i++){
			for(int j = 0 ; j < 8 ; j++){
				tab[i][j] = 0;
				mp[i][j] = '-';
			}
		}
	
		int lin = 0, col = 0;

		for(int i = 0 ; i < s.length() ; i++){

			if(s[i] == '/'){
				col = 0;
				lin++;
			}
			else if(s[i] >= '1' && s[i] <= '8'){
				col += s[i] - '0'; 
			}
			else{
				mp[lin][col] = s[i];
				tab[lin][col] = red;	
				col++;
			}
			
		}

		for(int i = 0 ; i < 8 ; i++){
			for(int j = 0 ; j < 8 ; j++){
				if(mp[i][j] == 'r' || mp[i][j] == 'R'){
					markHorizontal(i, j, tab);				
				}
				if(mp[i][j] == 'b' || mp[i][j] == 'B'){
					markDiagonal(i, j, tab);
				}
				if(mp[i][j] == 'N' || mp[i][j] == 'n'){
					markCustomized(i, j, tab, bx, by, 8);
				}
				if(mp[i][j] == 'q' || mp[i][j] == 'Q'){
					markHorizontal(i, j, tab);
					markDiagonal(i, j, tab);
				}
				if(mp[i][j] == 'k' || mp[i][j] == 'K'){
					markCustomized(i, j, tab, kx, ky, 8);
				}
				if(mp[i][j] == 'p'){
					markCustomized(i, j, tab, pBx, pBy, 2);
				}
				if(mp[i][j] == 'P'){
					markCustomized(i, j, tab, pWx, pWy, 2);
				}
			}
		}

		int cont = 0;
		for(int i = 0 ; i < 8 ; i++){
			for(int j = 0 ; j < 8 ; j++){
				if(tab[i][j] != white)
					cont ++;
			}
		}
		cout << 64 - cont << endl;
	}

	return 0;
}
