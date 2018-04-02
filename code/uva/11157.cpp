#include <bits/stdc++.h>

using namespace std;

vector<int>big, small;

int thereIsSmallAt(int l, int r, int t){
	int resp = -1;
	
	for(int i = 0 ; i < small.size() ; i++){
		if(small[i] > l && small[i] < r && (i % 2) == t){
			if(t == 0){
				return i;
			}else{
				resp = i;
			}
		}
	}
	
	return resp;
}

int main (){
	int t, test = 1;
		
	scanf("%d", &t);
	
	while(t--){
		int n, d;
		
		scanf("%d%d", &n, &d);
		
		for(int i = 0 ; i < n ; i++){
			char c;
			int l;
			
			scanf("\n%c-%d", &c, &l);
			
			if(c == 'B'){
				big.push_back(l);
			}else{
				small.push_back(l);
			}
		}
		
		int ans = 0;
		int cur = 0;
		
		if(big.size() == 0){
			for(int i = 0 ; i < small.size() ; i++){
				if(i % 2 == 0){
					ans = max(ans, small[i] - cur );
					cur = small[i];
				}
			}
			
			ans = max(ans, d - cur);
			cur = d;
			
			for(int i = small.size() - 1 ; i >= 0 ; i--){
				if(i % 2 == 1){
					ans = max(ans, cur - small[i]);
					cur = small[i];
				}	
			}
			
			ans = max(ans, cur);
		}else{
			int next;
			
			for(int i = 0 ; i < big.size() ; i++){
				
				while((next = thereIsSmallAt(cur, big[i], 0)) != -1){
					ans = max(ans, small[next] - cur);
				//	printf("%d->%d ", cur, small[next]);
					cur = small[next];
				}
				
			//	printf("%d->%d ", cur, big[i]);
				ans = max(ans, big[i] - cur);
				cur = big[i];
			}
			//printf("%d->%d\n", cur, d);
			
			while((next = thereIsSmallAt(cur, d, 0)) != -1){
				ans = max(ans, small[next] - cur);
				cur = small[next];
			}

			ans = max(ans, d - cur);			
			cur = d;
			
			for(int i = big.size() - 1 ; i >= 0  ; i--){
				int next;
				
				while((next = thereIsSmallAt(big[i], cur, 1)) != -1){
					ans = max(ans, cur - small[next]);
					//printf("%d<-%d\n", small[next], cur);
					cur = small[next];
					
				}
				//printf("%d<-%d\n", big[i], cur);
				ans = max(ans, cur - big[i]);
				cur = big[i];
			}
			
			while((next = thereIsSmallAt(0, cur, 1)) != -1){
				ans = max(ans, cur - small[next]);
				cur = small[next];
			}
			
			ans = max(ans, cur);
		}
		
		printf("Case %d: %d\n", test++, ans);
		
		small.clear();
		big.clear();
	}

	return 0;
}
