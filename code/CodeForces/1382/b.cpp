#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		int last = 0;
		int first = -1;
		int cnt = 0;

		for(int i = 0 ; i < n ; i++){
			int xi;

			scanf("%d", &xi);

			if(xi == 1){
				cnt++;
			}else if(first == -1){
				first = (i & 1);
			}

			last = xi;
		}

		if(cnt == n){
			if(cnt & 1){
				printf("First\n");
			}else{
				printf("Second\n");
			}
		}else{
			if(first){
				printf("Second\n");
			}else{
				printf("First\n");
			}
		}	
	}

	return 0;
}