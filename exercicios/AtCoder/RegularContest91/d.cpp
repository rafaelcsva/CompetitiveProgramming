#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 1e5 + 10;
vector<int>divisors[N];
#define insert	push_back

int main (){
	int n, k;
	
	cin >> n >> k;
	
	for(int i = 1 ; i <= n ; i++){
		for(int k = 1 ; k * k <= i ; k++){
			if(i % k == 0){
				divisors[i].insert(k);
				
				if(i / k != k)
					divisors[i].insert(i / k);
			}
		}
		
		sort(divisors[i].begin(), divisors[i].end());
	}
	
	ll count = 0LL;
	
	for(int i = k ; i <= n ; i++){
		if(i == k){
			cout << n - i << ' ' << i << '\n';
			count += max(0LL, ((ll)n - i ));
		}else{
			int l = upper_bound(divisors[i - k].begin(), divisors[i - k].end(), k) - divisors[i - k].begin();
			
			count += divisors[i - k].size() - l;
		}
	}
	
	cout << count << '\n';
	
	return 0;
}
