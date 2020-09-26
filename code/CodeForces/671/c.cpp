#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, x;

		scanf("%d %d", &n, &x);
			
		bool ver = false;
		bool ver1 = false;

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
			
			ver |= (a[i] != x);
			ver1 |= (a[i] == x);
		}

		if(ver){
			if(ver1){
				printf("1\n");
				continue;
			}
			
			int s = 0;

			for(int i = 0 ; i < n ; i++){
				s += (x - a[i]);
			}
			// printf("s: %d\n", s);
			printf("%d\n", 1 + (s != 0));
		}else{
			printf("0\n");
		}
	}

	return 0;
}