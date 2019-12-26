#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

int main(){
	int n;

	scanf("%d", &n);

	while(n--){
		long long ci, sumi;

		scanf("%lld %lld", &ci, &sumi);
		
		ll qtd1 = sumi % ci;
		ll qtd2 = ci - qtd1;
		ll a = sumi / ci;
		ll b = sumi / ci;

		if(qtd1){
			a++;
		}

		cout << a * a * qtd1 + b * b * qtd2 << endl;
	}

	return 0;
}