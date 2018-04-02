#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
int v[N];
int cnt[N];

int main (){
	int n;
	
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	int mx = 0;
	
	for(int i = 0 ; i < n ; i++){
		
		cin >> v[i];
		
		cnt[v[i]]++;
		
		mx = max(mx, v[i]);
	}

	bool ver = false;
	
	for(int i = 0 ; i < n ; i++){
		if(cnt[v[i]] % 2){
			
			ver = true;
		}
	}
	
	if(ver){
		cout << "Conan\n";
	}else{
		cout << "Agasa\n";
	}

}
