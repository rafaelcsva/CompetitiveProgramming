#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
char color[N];

int mod(int i, int n){
	return (i + n) % n;
}

int n, q;

bool isOk(char c, char d){
	if(c != 'R' && c != 'G')
		return false;
		
	if(d != 'R' && d != 'G')
		return false;
		
	return true;
}

int next(int i){
	if(i == n)
		return 1;
		
	return i + 1;
}

int past(int i){
	if(i == 1)
		return n;
		
	return i - 1;
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		
		scanf("%d%d", &n, &q);
		
		for(int i = 1 ; i <= n ; i++){
			scanf("\n%c", &color[i]);
		}
		
		while(q--){
			int x, y;
			
			scanf("%d%d", &x, &y);
			
			int cnd1 = 0, cnd2 = 0;
			
			int i = x;
			
			while(true){
				if(i != x){
					if(color[past(i)] != color[i]){
						cnd1++;
					}
				}
				
				if(i == y){
					break;
				}
				
				if(i == n){
					i = 1;
				}else{
					i++;
				}
			}
			
			i = x;
			
			while(true){
				if(i != x){
					if(color[next(i)] != color[i]){
						cnd2++;
					}
				}
				
				if(i == y){
					break;
				}
				
				if(i == 1){
					i = n;
				}else{
					i--;
				}
			}
			
			printf("%d\n", min(cnd1, cnd2));
		}
	}
	
	return 0;
}
