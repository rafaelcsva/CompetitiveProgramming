#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6);
int a[N];

int main(){
	int n;

	scanf("%d", &n);

	int mx = 0;
	int mx1 = 0;

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);

		if(a[i] >= mx){
			mx1 = mx;
			mx = a[i];
		}else{
			mx1 = max(mx1, a[i]);
		}
	}

	int cnt = 0;

	for(int i = 0 ; i < n ; i++){
		if(a[i] == mx){
			cnt++;
		}
	}

	if(cnt > 1){
		for(int i = 0 ;i < n ; i++){
			printf("%d\n", mx);
		}
	}else{
		for(int i = 0 ; i < n ; i++){
			if(a[i] == mx){
				printf("%d\n", mx1);
			}else{
				printf("%d\n", mx);
			}
		}
	}

	return 0;
}