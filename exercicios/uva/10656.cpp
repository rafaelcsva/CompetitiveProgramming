#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1010;
int v[N];

int main (){
	int n;
	
	while(scanf("%d", &n)){
		if(n == 0)
			break;
			
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
		}
		
		int l = n, r = 0;
		
		for(int i = 0 ; i < n ; i++){
			if(v[i] != 0){
				l = min(l, i);
				r = max(r, i);
			}
		}
		
		for(int i = l ; i <= r ; i++){
			char c = i == r ? '\n' : ' ';
			if(v[i] == 0)
				continue;
				
			printf("%d%c", v[i], c);
		}
		if(l > r){
			printf("0\n");
		}
	}
	
	return 0;
}
