#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10, bg = 1, ed = (int) 1e7;
int v[N];
int n;

bool isPossible(int k){
	if(v[0] > k)
		return false;
		
	if(v[0] == k){
		k--;
	}
	
	for(int i = 1 ; i < n ; i++){
		int diff = v[i] - v[i - 1];
		
		if(diff > k){
			return false;
		}
		
		if(diff == k){
			k--;
		}
	}
	
	return true;
}

int main (){
	int t;
	int test = 1;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}	
		
		int ini = bg, fim = ed;
		
		while(ini < fim){
			int mid = (ini + fim) / 2;
			
			if(isPossible(mid)){
				fim = mid;
			}else{
				ini = mid + 1;
			}
		}
		
		printf("Case %d: %d\n", test++, (ini + fim) / 2);
	}

	return 0;
}
