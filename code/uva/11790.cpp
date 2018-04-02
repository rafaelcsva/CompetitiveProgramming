#include <bits/stdc++.h>

using namespace std;

const int N = 10100;
int LIS[N], LDS[N], h[N], w[N];

int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		int n;
		
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &h[i]);
		}
		
		for(int i = 0; i < n ; i++){
			scanf("%d", &w[i]);
		}
		
		int anslis = 0, anslds = 0;
		
		for(int i = 0 ; i < n ; i++){
			LIS[i] = w[i];
			LDS[i] = w[i];
			
			for(int j = 0 ; j < i ; j++){
				if(h[j] < h[i]){
					LIS[i] = max(LIS[i], w[i] + LIS[j]);
				}
				
				if(h[j] > h[i]){
					LDS[i] = max(LDS[i], w[i] + LDS[j]);
				}
			}
			
			anslis = max(LIS[i], anslis);
			anslds = max(LDS[i], anslds);
		}
		
		if(anslis >= anslds){
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", test++, anslis, anslds);
		}else{
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", test++, anslds, anslis);
		}
	}

	return 0;
}
