#include <bits/stdc++.h>

using namespace std;

const int N = 10100;
int v[N];

int main (){
	int n;
	int cnt = 0;
	int m = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n ; i++){
		scanf("%d", &v[i]);
		cnt += v[i];
	}
	
	int i = 0;
	
	while(i < n){
		if(v[i] == 0){
			i++;
			continue;
		}
		
		m++;
		i += 2;
	}
	
	printf("%d %d\n", m, cnt);
	
	return 0;
}
