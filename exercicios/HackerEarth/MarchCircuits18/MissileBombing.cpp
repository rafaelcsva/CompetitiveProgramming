#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int mark[N][N];

int main (){
	int n;
	int m;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	for(int i = 0 ; i < m ; i++){
		int p, a, b, c, d;
		
		scanf("%d%d%d%d%d", &p, &a, &b, &c, &d);
		
		for(int i = a ; i <= c ; i++){
			mark[i][b] ^= p;
			mark[i][d + 1] ^= p;
		} 
	}
	
	for(int i = 0 ; i <= n ; i++){
		int ac = 0;
		
		for(int j = 0 ; j <= n ; j++){
			ac ^= mark[i][j];
			mark[i][j] = ac; 
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			char c = j == n ? '\n' : ' ';
			
			printf("%d%c", mark[i][j], c);
		}
	}
	
	return 0;
}
