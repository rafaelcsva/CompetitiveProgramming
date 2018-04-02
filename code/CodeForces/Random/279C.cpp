#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
int a[N];
int markL[N], markR[N], mark[N];

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 1 ; i <= n ; i++){
		if(a[i] < a[i + 1]){
			mark[i] = 1;
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		if(mark[i - 1]){
			markL[i] = i - 1;
		}else{
			markL[i] = markL[i - 1];
		}
	}
	
	markR[n + 1] = n + 1;
	
	for(int i = n ; i >= 1 ; i--){
		if(mark[i + 1]){
			markR[i] = i + 1;
		}else{
			markR[i] = markR[i + 1];
		}
	}
	
	while(m--){
		int l, r;
		
		scanf("%d%d", &l, &r);
		
		if(markR[l] < r || markL[r] > l){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	
	return 0;
}
