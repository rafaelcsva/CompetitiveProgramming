#include <bits/stdc++.h>

using namespace std;

#define MAXN	100100

int pos[MAXN];

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	bool ok = true;
	
	while(m--){
		int l, r, d;
		
		scanf("%d %d %d", &l, &r, &d);
		
		if(pos[l] != 0 && pos[d] != 0){
			ok = false;
		}else if(pos[r] != 0){
			pos[r] = 
		}
	}

	return 0;
}
