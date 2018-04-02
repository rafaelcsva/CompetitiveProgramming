#include <bits/stdc++.h>

using namespace std;

map<int, int>mp;
int dp[10][20100], used[10][20100], qtd[4];

int solve(int coin, int amount){
	if(amount < 0){
		return 0;
	}
	
	if(amount == 0){
		return 1;
	}
	
	if(coin > 2){
		return 0;
	}
	
	int &ans = dp[coin][amount];
	
	if(used[coin][amount]){
		return ans;
	}
	
	used[coin][amount] = 1;
	
	for(int k = 0 ; k <= qtd[coin]; k++){
		ans += solve(coin + 1, amount - k * mp[coin]);
	}
	
	return ans;
}
int main (){
	mp[0] = 500;
	mp[1] = 100;
	mp[2] = 50;

	for(int i = 0 ; i < 3 ; i++){
		cin >> qtd[i];
	}		
	
	int x;
	
	cin >> x;
	
	cout << solve(0, x) << '\n';
	
	return 0;
}
