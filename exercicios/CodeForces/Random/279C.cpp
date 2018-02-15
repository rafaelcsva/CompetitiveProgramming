#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 100;
int a[N], p[N], f[N];

int main (){
	int n, m;
	
	scanf("%d%d", &n, &m);
	
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
	}
	
	int d = 0;
	
	if(a[1] > a[2]){
		d = 1;
	}
	
	for(int i = 3 ; i <= n ; i++){
		if(d == 0){
			if(a[i] < a[i - 1]){
				p[i] = 1;
				d = 1;
			}
		}else{
			if(a[i] > a[i - 1]){
				p[i] = 1;
				f[i - 1] = 1;
				d = 0;
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		p[i] += p[i - 1];
		f[i] += f[i - 1];
	}
	
	while(m--){
		int l, r;
		
		scanf("%d%d", &l, &r);
		
		if(n == 1 || l == r){
			printf("Yes\n");
			continue;
		}
		
		int h = p[r] - p[l];
		int g = f[r - 1] - f[l];
		
		if(h <= 1 && !g){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	
	return 0;
}
