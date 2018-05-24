#include <bits/stdc++.h>

using namespace std;

string s;
int k;
const int N = int(1e3 + 10);
bool dp[N][N], used[N][N];
typedef pair<bool, string>	tp;

tp solve(int n, int j){
	if(n == s.length()){
		return {j % k == 0, ""};
	}
	
	if(used[n][j]){
		return {dp[n][j], ""};
	}
	
	used[n][j] = true;
	
	if(s[n] != '?'){
		tp r = solve(n + 1, (j * 10 + s[n] - '0') % k);
		if(r.first){
			dp[n][j] = true;
			return {true, s[n] + r.second};
		}
	}
	else{
		for(int i = n == 0 ; i <= 9 ; i++){
			tp r = solve(n + 1, (j * 10 + i) % k);
		
			if(r.first){
				dp[n][j] = true;
				return {true, char(i + '0') + r.second};
			}
		}
	}
	return {false, ""};
}

int main(){
	
	cin >> s;
	cin >> k;
	
	tp r = solve(0, 0);
	
	if(r.first){
		cout << r.second << endl;
	}else{
		cout << "*" << endl;
	}
	
	return 0;
}
