#include <bits/stdc++.h>

using namespace std;

int cnt[1010];

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0 ; i < n ; i++){
		int x;
		
		scanf("%d", &x);
		
		cnt[x]++;
	}
	
	for(int i = 0 ; i < m ; i++){
		char c = i == m - 1 ? '\n' : ' ';
		
		printf("%d%c", cnt[i], c);
	}
	
	return 0;
}
