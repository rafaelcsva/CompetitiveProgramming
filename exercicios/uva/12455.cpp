#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int l[N];
int n, p;

bool backtracking(int i, int sum){
	if(i == p){
		return sum == n;
	}else{
		bool isPossibly = false;
		
		isPossibly = isPossibly || backtracking(i + 1, sum + l[i]);
		isPossibly = isPossibly || backtracking(i + 1, sum);
		
		return isPossibly;
	}
}

int main (){
	int t;
	
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--){
		
		cin >> n >> p;
		
		for(int i = 0 ; i < p ; i++){
			cin >> l[i];
		}
		
		if(backtracking(0, 0)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	
	return 0;
}
