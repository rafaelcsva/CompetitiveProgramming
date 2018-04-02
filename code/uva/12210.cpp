#include <bits/stdc++.h>

using namespace std;

const int N = 100, M = (int) 1e5;
int cnt[N], bac[M];

int main (){
	int b, s, test = 1;
	
	while(scanf("%d%d", &b, &s)){
		if(b == 0 && s == 0){
			break;
		}
		
		for(int i = 0 ; i < b ; i++){
			
			scanf("%d", &bac[i]);
			
		}
		
		sort(bac, bac + b, greater<int>());
		
		for(int i = 0 ; i < s ; i++){
			int a;
			
			scanf("%d", &a);
			
			cnt[a]++;
		}

		int i;
		
		for(i = 0 ; i < b ; i++){
			int sup = -1, bott = -1;
			
			for(int j = bac[i] ; j <= 60 ; j++){
				if(cnt[j] >= 1){
					sup = j;
					break;
				}
			}	
			
			for(int j = bac[i] ; j >= 2 ; j--){
				if(cnt[j] >= 1){
					bott = j;
				}
			}
			
			int r = -1;
			
			if(bott == -1){
				r = sup;
			}else if(sup == -1){
				r = bott;
			}else{
				if(abs(bac[i] - sup) <= abs(bac[i] - bott)){
					r = sup;
				}else{
					r = bott;
				}
			}
			
			if(r == -1){
				break;
			}else{
				cnt[r]--;
			}
		}
		
		int diff = b - i;
		
		printf("Case %d: ", test++);
		
		printf("%d", diff);
		
		if(diff != 0){
			printf(" %d\n", bac[b - 1]);
		}else{
			printf("\n");
		}
		
		for(i = 2 ; i <= 60 ; i++){
			cnt[i] = 0;
		}
	}
	
	return 0;
}
