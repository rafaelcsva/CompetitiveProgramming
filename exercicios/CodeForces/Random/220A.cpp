#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
int v[N], c[N];

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &v[i]);
		
		c[i] = v[i];
	}
	
	sort(v, v + n);
	
	int cnt = 0;
	
	for(int i = 0 ; i < n ; i++){
		if(c[i] != v[i]){
			cnt++;
		}
	}
	
	if(cnt <= 2){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
	
	return 0;
}
