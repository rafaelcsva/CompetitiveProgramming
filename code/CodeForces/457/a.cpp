#include <bits/stdc++.h>

using namespace std;

int main (){
	int x;
	int h, m;
	
	int H[3] = {7, 17, 27};
	int M[6] = {7, 17, 27, 37, 47,  57};
	
	scanf("%d", &x);
	scanf("%d%d", &h, &m);
	
	int y = 100;
	int tm = 60 * h + m;
	
	for(int k = 0 ;k < 24 ; k++){
		for(int j = 0 ; j < 60 ; j++){
			bool ver = false;
			
			for(int i = 0 ; i < 6 ; i++){
				if(j == M[i])
					ver = true;
			}
			
			for(int i = 0 ; i < 3 ; i++){
				if(H[i] == k){
					ver = true;
				}
			}
			
			if(ver){
			
				int totm = 60 * k + j;
				
				int diff;
				
				if(totm > tm){
					diff = 24 * 60 - totm + tm;
				}else{
					diff = abs(totm - tm);
				}
				
				if(diff % x == 0){
					
						
					
					y = min(y, diff / x);
				}
			}
		}
	}
	
	printf("%d\n", y);
	
	return 0;
}
