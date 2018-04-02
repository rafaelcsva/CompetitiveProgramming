#include <bits/stdc++.h>

using namespace std;

const int N = 200100;
typedef long long	ll;
ll x[N];
ll dp[N], k, b;
int n;

int binary_search(ll e, int end){
	int ini = 0;
	int r = -1;
	
	while(ini <= end){
		int mid = (ini + end) / 2;
		
		if(x[mid] * k + b <= e){
			r = mid;
			ini = mid + 1;
		}else{
			end = mid - 1;
		}
	}
	
	return r;
}

int main (){
	int t;
	
	cin >> t;
	
	while(t--){
		
		cin >> n >> k >> b;
		
		for(int i = 0 ; i < n ; i++){
			cin >> x[i];
		}
		
		sort(x, x + n);
		
		ll ans = 0LL;
		
		for(int i = 0 ; i < n ; i++){
			dp[i] = 1LL;
			
			int j = binary_search(x[i], i - 1);
			
			if(j != -1){
				dp[i] += dp[j];
			}
			
			ans = max(ans, dp[i]);
		
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
