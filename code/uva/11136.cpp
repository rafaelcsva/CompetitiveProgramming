#include <bits/stdc++.h>
#include <functional> 

using namespace std;

typedef long long int	lli;
multiset<int>bills;
multiset<int>::iterator down, up;

int main (){
	int n;

	while(scanf("%d", &n)){
		if(n == 0)
			break;

		int k;
		lli cost = 0;
		
		for(int j = 0 ; j < n ; j++){
			scanf("%d", &k);

			for(int i = 0 ; i < k ; i++){
				int b;
	
				scanf("%d", &b);
	
				bills.insert(b);
			}
			down = bills.begin();
			up = prev(bills.end());

			cost = cost + *up - *down;

			bills.erase(down);
			bills.erase(up);
		}

		printf("%lld\n", cost);

		bills.clear();
	}	

	return 0;
}
