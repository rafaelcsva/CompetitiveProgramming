#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		if(n <= 30){
			printf("NO\n");
		}else{
			if(n - 30 == 6 || n - 30 == 10 || n - 30 == 14){
				if(n <= 31){
					printf("NO\n");
				}else{
					printf("YES\n6 10 15 %d\n", n - 31);
				}
			}else{
				printf("YES\n6 10 14 %d\n", n - 30);
			}
		}
	}

	return 0;
}