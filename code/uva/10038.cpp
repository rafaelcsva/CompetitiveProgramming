#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
int ver[N];
int a[N];

int main (){
	int n;

	while(scanf("%d", &n) != EOF){
		for(int i = 1 ; i <= n ; i++){
			ver[i] = 0;
		}

	
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		int ans = 0;
		for(int i = 1 ; i < n ; i++){
			int s = abs(a[i] - a[i - 1]);

			if(s >= 1 && s < n && ver[s] == 0){
				ans++;
				ver[s] = 1;
			}
		}

		if(ans == n - 1){
			printf("Jolly\n");
		}else{
			printf("Not jolly\n");
		}
	}

	return 0;
}
