#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int v[N];

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		int n;
		
		scanf("%d", &n);

		int cnt = 0;
				
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
			
			for(int j = 0 ; j < i ; j++){
				if(v[j] <= v[i]){
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}

	return 0;
}
