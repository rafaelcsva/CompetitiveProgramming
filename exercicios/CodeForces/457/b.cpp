#include <bits/stdc++.h>

using namespace std;

ll one = 1;

void makeN(ll n, int c){
	if(n == 0){
		return;
	}
	
	for(ll j = n ; j >= -64 ; j--){
		ll tmp = one << (n - j);
		
		if(tmp > c){
			tmp -= one << (n - (j - 1));
			
		}	 
	}
}

int main (){
	ll n, k;
	
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	
	bitset<64>st(n);
	
	int cnt = 0;
	ll f = -1;
	int l = -1;
	for(int i = 0 ; i < 64 ; i++){
		if(st[i] == 1){
			cnt++;
			
			if(l == -1){
				l = i;
			}
			
			f = i;
		}
	}
	
	if(cnt > k){
		cout << "No\n";
	}else{
		cout << "Yes\n";
		
		int diff = k - cnt + 1;
		
		for(int k = 0 ; k <= diff ; k++){
			cout << f - diff << ' ';
		}
		
		makeN(one << f, diff);
		
		k -= (diff + 1);
		
		for(int j = f - 1 ; j > l ; j++){
			if(st[j] == 1){
				cout << j << ' ';
				k--;
			}
		}
		
		
	}
	
	return 0;
}
