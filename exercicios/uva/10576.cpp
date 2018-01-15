#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e7;
int ans = -inf;

int main (){
	int s, d;
	
	while(scanf("%d%d", &s, &d) != EOF){
		
		for(int i = 0 ; i < 1 << 13 ; i++){
			int tmp = 0;
			int pts = 0;
			
			for(int j = 0 ; j < 12 ; j++){
				if(i & (1 << j)){
					tmp += s;
				}else{
					tmp -= d;
				}
			}
			
			bool isValid = true;
			
			for(int j = 0 ; j <= 12 - 5; j++){
				int tmp = 0;
				
				for(int k = 0; k < 5 ; k++){
					int m = k + j;
					
					if(i & (1 << m)){
						tmp += s;
					}else{
						tmp -= d;
					}
				} 
				
				if(tmp >= 0){
					isValid = false;
				}
			}
			
			if(tmp >= 0 && isValid){
				ans = max(ans, tmp);
			}
			
		}
		
		if(ans >= 0){
			printf("%d\n", ans);
		}else{
			printf("Deficit\n");
		}
		
		ans = -inf;
	}

	return 0;
}
