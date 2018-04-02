#include <bits/stdc++.h>

#define MAXIMO	110
#define INF	9999999

using namespace std;

int main (){
	string s;
	int dp[MAXIMO];
	
	cin>>s;
	
	int maior = -1;
	
	for(int i = 0 ; i < s.length() ; i++){
		dp[i] = 1;
		
		for(int j = 0 ; j < i ; j++){
			if(s[j] < s[i]){
				if(dp[i] < dp[j]+1)
					dp[i] = dp[j]+1;
			}
		}
		
		maior = max(dp[i], maior);
	}
	cout<<26-maior<<"\n";
	
	return 0;
}
