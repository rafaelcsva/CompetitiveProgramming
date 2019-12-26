#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const ll N = ll(61);
vector< ll > numbers[N];
vector< ll > del;

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		ll ai;

		scanf("%lld", &ai);

		int cnt = 0;
		ll tmp = ai;

		while(tmp % 2LL == 0LL){
			cnt++;
			tmp >>= 1LL;
		}

		// printf("%d\n", cnt);

		numbers[cnt].push_back(ai);
	}

	int aux = 0;

	for(int i = 0 ; i < N ; i++){
		if(numbers[i].size() > numbers[aux].size()){
			aux = i;
		}
	}

	// printf("aux = %d\n", aux);

	for(int i = 0 ; i < N ; i++){
		if(i != aux){
			for(ll u: numbers[i]){
				del.push_back(u);
			}
		}
	}

	printf("%lu\n", del.size());

	for(auto u: del){
		printf("%lld ", u);
	}

	printf("\n");

	return 0;
}