#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e7;

int main (){
	int n;

	scanf("%d", &n);
	
	bool flag = false;
	int n7 = INF, n4 = INF;

	for(int i = 0 ; n - i * 7 >= 0 ; i++){
		int tmp = n - i * 7;

		if(tmp % 4 == 0){
			flag = true;
			
			if(i + tmp / 4 < n7 + n4){
				n7 = i;
				n4 = tmp / 4;				
			}else if(i + tmp / 4 == n7 + n4){
				if(i < n7){
					n7 = i;
					n4 = tmp / 4;
				}
			}						
		}
	}

	if(!flag){
		printf("-1\n");
	}
	else{
		for(int i = 0 ; i < n4 ; i++){
			printf("4");
		}
		for(int i = 0 ; i < n7 ; i++){
			printf("7");
		}
	
		printf("\n");
	}

	return 0;
}
