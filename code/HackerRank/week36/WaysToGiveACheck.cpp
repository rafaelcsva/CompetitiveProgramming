#include <bits/stdc++.h>

using namespace std;

const int N = 8;
char tab[N][N];
int horsei[8] = {1, 1, 2, 2, -2, -2, -1, -1};
int horsej[8] = {-2, 2, -1, 1, -1, 1, -2, 2};
int kingi[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int kingj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int pawni[2] = {-1, -1};
int pawnj[2] = {-1, 1};

int horse(int l, int c){
	int way = 0;
	
	for(int i = 0 ; i < 8; i++){
		int tmpl = l + horsei[i];
		int tmpc = c + horsej[i];
		
		if(tmpl >= 0 && tmpl < 8 && tmpc >= 0 && tmpc < 8 && tab[tmpl][tmpc] == 'k'){
			way++;
			break;
		}
	}
	
	return way;
}

int rookqueen(int l, int c){
	int way = 0;
	
	for(int i = l - 1 ; i >= 0 ; i--){//up
		if(tab[i][c] != '#'){
			if(tab[i][c] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	for(int i = l + 1 ; i < 8; i++){//down
		if(tab[i][c] != '#'){
			if(tab[i][c] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	for(int j = c + 1 ; j < 8 ; j++){//right
		if(tab[l][j] != '#'){
			if(tab[l][j] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	for(int j = c - 1 ; j >= 0 ; j--){//left
		if(tab[l][j] != '#'){
			if(tab[l][j] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	return way;
}

int bishopqueen(int l, int c){
	int way = 0;
	
	for(int i = l - 1, j = c - 1 ; i >= 0 && j >= 0 ; i--, j--){
		if(tab[i][j] != '#'){
			if(tab[i][j] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	for(int i = l - 1 , j = c + 1 ; i >= 0 && j < 8 ; i--, j++){
		if(tab[i][j] != '#'){
			if(tab[i][j] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	for(int i = l + 1, j = c - 1 ; i < 8 && j >= 0 ; i++, j--){
		if(tab[i][j] != '#'){
			if(tab[i][j] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	for(int i = l + 1 , j = c + 1 ; i < 8 && j < 8 ; i++, j++){
		if(tab[i][j] != '#'){
			if(tab[i][j] == 'k'){
				way += 2;
			}
			
			break;
		}
	}
	
	return way;
}

int king(int l, int c){
	int way = 0;
	
	for(int i = 0 ; i < 8 ; i++){
		int tl = kingi[i] + l;
		int tc = kingj[i] + c;
		
		if(tl >= 0 && tl < 8 && tc >= 0 && tc < 8 && tab[tl][tc] == 'k'){
			way++;
			break;
		}
	}
	
	return way;
}

int pawn(int l, int c){
	int way = 0;
	
	for(int i = 0 ; i < 2 ; i++){
		int tl = pawni[i] + l;
		int tc = pawnj[i] + c;
		
		if(tl >= 0 && tl < 8 && tc >= 0 && tc < 8){
			way++;
			break;
		}
	}
	
	return way;
}

int WaysToGiveACheck(int c){
	return horse(0, c) + rookqueen(0, c) + bishopqueen(0, c);
}

bool AlreadyCheck(int c){
	int ck = 0;
	
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(i == 0 && j == c){
				continue;
			}
			
			if(tab[i][j] == 'K'){
			//	ck += king(i, j);
			}else if(tab[i][j] == 'Q'){
				ck += bishopqueen(i, j);
				ck += rookqueen(i, j);
			}else if(tab[i][j] == 'N'){
			//	ck += horse(i, j);
			}else if(tab[i][j] == 'B'){
				ck += bishopqueen(i, j);
			}else if(tab[i][j] == 'R'){
				ck += rookqueen(i, j);
			}else if(tab[i][j] == 'P'){
			//	ck += pawn(i, j);
			}
		}
	}
	
	return ck > 0;
}

int main (){
	int t;

	scanf("%d", &t);
	
	while(t--){
		for(int i = 0 ; i < 8 ; i ++){
			for(int j = 0 ; j < 8 ; j++){
				scanf("\n%c", &tab[i][j]);
			}
		}
		
		for(int i = 0 ; i < 8 ; i++){
			if(tab[1][i] == 'P'){
				if(tab[0][i] == '#'){
					tab[1][i] = '#';
					tab[0][i] = 'P';
					
					if(AlreadyCheck(i)){
						printf("4\n");
					}else{
						printf("%d\n", WaysToGiveACheck(i));
					}
					break;
				}
			}
		}
		
	}
	
	return 0;
}
