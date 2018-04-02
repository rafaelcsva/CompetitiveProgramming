#include <bits/stdc++.h>

using namespace std;
const int N = 120;
int tab[N][N];
int ok[N][N];

int main (){
	int i, j;
	int w, b;
	
	cin >> w >> b;
	
	for(i = 1 ; i <= 100 ; i++){
		int p = (i - 1) % 2;
		
		for(j = 1 ; j <= 100 ; j++){
			if(p){
				b--;
			}else{
				w--;
			}
				
			tab[i][j] = p;	
			
			p = !p;
			
			if(!w || !b)
				break;
		}
		
		if(!w || !b){
			break;
		}
	}

	for(; i <= 100 ; i++){
		for(j = 1 ; j <= 100 ; j++){
			
		}
	}
	
	return 0;
}
