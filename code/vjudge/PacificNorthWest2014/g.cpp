#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = 100;
ll f[N];

int main(){
	f[0] = f[1] = 1LL;

	f[2] = 2LL;

	f[3] = 4LL;

	for(int i = 4 ; i < N ; i++){
		f[i] = f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4];
	}

	int t;

	scanf("%d", &t);

	while(t--){
		int g;

		scanf("%d", &g);
		
		printf("%lld\n", f[g]);
	}

	return 0;
}