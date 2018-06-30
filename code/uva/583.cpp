#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 1 << 16;
vector<ll>primes;
bool isComposite[N];

void sieve(){
	for(int i = 2 ; i * i < N ; i++){
		if(!isComposite[i]){
			for(int j = i * i ; j < N ; j += i){
				isComposite[j] = true;
			}
		}
	}
	
	for(int i = 2 ; i < N ; i++){
		if(!isComposite[i]){
			primes.push_back(i);
		}
	}
}

int main(){
	ll n;
	
	while(scanf("%lld", &n) != EOF){
		if(n == 0)
			break;
		
		if(n < 0)
			n *= -1LL;
			
		bool has = false;
		
		ll tn = n;
		ll best = -1;
		int cnt = 0;
		
		for(ll k = 2LL ; k * k <= n ; k++){
			
			if(tn % k == 0)
				cnt++;
			while(tn % k == 0LL){
				best = max(best, k);
				tn /= k;
			}
		}
		
		if(tn != 1){
			cnt++;
			best = max(best, tn);
		}
		
		if(cnt <= 1){
			printf("-1\n");
			continue;
		}
			
		
		printf("%lld\n", best);
	}
	
	return 0;
}
