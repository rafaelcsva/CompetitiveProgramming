#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int tab[N][N], vis[N][N], cnt[N][N];
int t;
int r, c, m, n;
enum color{white, black, blue, red};

void dfs(int x, int y){
	vis[x][y] = black;
	
	for(int k = 0 ; k < 2 ; k++){
		int addi, addj;
		
		if(k == 0){
			addi = m;
			addj = n;
		}else{
			addi = n;
			addj = m;
		}
		
		for(int i = -1, g = 0; g < 2; i *= -1, g++){
			for(int j = -1, u = 0 ; u < 2 ; j *= -1, u++){
				int ti = addi * i + x;
				int tj = addj * j + y;
				
				if(ti >= 0 && ti < r && tj >= 0 && tj < c){
					if(tab[ti][tj] == blue){
						cnt[x][y]++;
						
						if(vis[ti][tj] == white){
							dfs(ti, tj);
						}
					}
				}
				
				if(addj == 0){
					break;
				}	
			} 
			
			if(addi == 0){
				break;
			}
		}
		
		if(addi == addj){
			break;
		}
	}
	
}

int main (){
	scanf("%d", &t);
	
	for(int test = 1 ; test <= t ; test++){
		
		scanf("%d%d%d%d", &r, &c, &m, &n);
		
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				tab[i][j] = blue;
				vis[i][j] = white;
				cnt[i][j] = 0;
			}
		}
		
		int w;
		
		scanf("%d", &w);
		
		for(int i = 0 ; i < w ; i++){
			int x, y;
			
			scanf("%d%d", &x, &y);
			
			tab[x][y] = red;
		}
		
		int sumev = 0, sumod = 0;
		
		dfs(0, 0);
		
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				if(vis[i][j] == black){
					sumev += cnt[i][j] % 2 == 0;
					sumod += cnt[i][j] % 2 == 1;
				}
			}
		}
		
		printf("Case %d: %d %d\n", test, sumev, sumod);
		
	}
	
	return 0;
}
