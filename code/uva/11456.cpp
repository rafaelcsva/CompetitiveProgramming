#include <bits/stdc++.h>

using namespace std;

const int N = 3000;
int LIS[N], LDS[N];
int v[N];

int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		int n;
		
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}

		for(int i = n - 1 ; i >= 0 ; i--){
			LIS[i] = 1;
		
			for(int j = i + 1 ; j < n ; j++){
				if(v[j] > v[i]){
					LIS[i] = max(LIS[i], LIS[j] + 1);
				}
			}
		}
		
		for(int i = n - 1 ; i >= 0 ; i--){
			LDS[i] = 1;
			
			for(int j = i + 1 ; j < n ; j++){
				if(v[j] < v[i])
					LDS[i] = max(LDS[i], LDS[j] + 1);
			}
		}
		
		int ans = 0;
		
		for(int i = 0 ; i < n ; i++){
			ans = max(ans, LDS[i] + LIS[i] - 1);
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
