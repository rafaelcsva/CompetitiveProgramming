#include <bits/stdc++.h>

using namespace std;

map<int, int>ind;

int main (){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		int ans = 0;
		int cur = 0;	
		
		for(int i = 1 ; i <= n ; i++){
			int c;
	
			scanf("%d", &c);

			if(ind[c] == 0){
				cur++;
			}else{
				cur = min(i - ind[c], cur + 1);
			}

		//	printf("%d %d\n", i, cur);

			ans = max(ans, cur);
			ind[c] = i;
		}
	
		printf("%d\n", ans);

		ind.clear();
	}

	return 0;
}
