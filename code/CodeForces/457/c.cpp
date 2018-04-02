#include <bits/stdc++.h>

using namespace std;

const int magic = 1299821, mx = (int) 1e9;

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	printf("%d %d\n", magic, magic);
	
	for(int i = 2 ; i < n ; i++){
		printf("%d %d 1\n", i, i - 1);
	} 
	
	printf("%d %d %d\n", n - 1, n, magic - (n - 2));
	
	m -= (n - 1);
	
	for(int i = 1 ; i <= n && m ; i++){
		for(int j = i + 2 ; j <= n && m ; j++){
			printf("%d %d %d\n", i, j, mx);
			m--;
		}
	}
	
	return 0;
}
