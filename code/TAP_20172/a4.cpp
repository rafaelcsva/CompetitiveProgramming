#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	scanf("%d", &n);
	
	int cnt = 0;
	int fat = 1;
	int termo = 1;
	
	while(n > 0){
		if((termo+1)*fat > n){
			cnt++;
			
			n-=fat;
			
			fat = 1;
			
			termo = 1;
		}else{
			termo++;
			fat = fat*(termo);
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
