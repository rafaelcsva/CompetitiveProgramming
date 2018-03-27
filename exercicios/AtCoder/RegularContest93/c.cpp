#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 100;
int a[N];
int f[N];
int n;

int build(int x){
	if(x == n + 1)
		return 0;
		
	return f[x] = build(x + 1) + abs(a[x] - a[x + 1]);
}

int main (){
	
	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	
	build(0);
	
	for(int i = 1 ; i <= n ; i++){
		if(i == 1){
			cout << f[i + 1] + abs(a[i + 1]) << '\n';
		}else if(i == n){
			cout << f[0] - f[n - 1] + abs(a[n - 1]) << '\n';
		}else{
			cout << f[0] - f[i - 1] + abs(a[i - 1] - a[i + 1]) + f[i + 1] << '\n' ;
		}
	}
	
	return 0;
}
