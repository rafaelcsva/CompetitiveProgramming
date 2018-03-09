#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
const int N = 100100;
lli pre[N], a[N];

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);
	}
	
	lli s, f;
	
	scanf("%lld %lld", &s, &f);
	
	for(int i = 0 ; i < n ; i++){
		pre[i] = a[i];
		
		if(i > 0){
			pre[i] += pre[i - 1];
		}
	}
	
	int k = f - s - 1;
	int ans = 0;
	int time = 1;
	
	for(int i = 0 ; i < n ; i++){
		lli tot = 0;
		
		int tr = i + s - 1;
		
		if(tr > 0){
			if(tr >= n){
				tr -= n;
			}
			
			int mn = min(tr + k, n - 1);
			
			tot = pre[mn] - pre[tr - 1];
		}else{
			tot = pre[tr + k];
		}
		
		if(tr + k >= n){
			int m = (tr + k) - n;
			tot += pre[m];
		}
		
		if(tot > ans){
			ans = tot;
			
			if(i != 0)
				time = n - i + 1;
			
		}else if(tot == ans){
			time = min(n - i + 1, time);
		}
		
	}
	
	printf("%d\n", time);
	
	return 0;
}
