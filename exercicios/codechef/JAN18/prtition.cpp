#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;

set<lli>p1, p2;
set<lli>::iterator it1, it2;

int main (){
	int t;

	ios::sync_with_stdio(false);

	cin >> t;

	while(t--){
		p1.clear();
		p2.clear();

		lli x, n;
		lli one = 1, two = 2;

		cin >> x >> n;

		lli sum = ((((one + n) * n) / two) - x);
		
		if(sum % two){
			cout << "impossible\n";
			continue;
		}

		sum = sum / two;

		lli sum2 = sum;

		
		for(lli i = n ; i >= one; i--){
			if(i == x)
				continue;
	
			if(sum == 0 || sum - i < 0 || sum - i == x){
				p2.insert(i);
				sum2 -= i;
				continue;
			}
			
			p1.insert(i);
			sum -= i;
		}

		if(sum2 != 0 || sum != 0){
			cout << "impossible\n";
			continue;		
		}

		for(lli i = one ; i <= n ; i++){
			it1 = p1.find(i);
			it2 = p2.find(i);
	
			if(it1 != p1.end()){
				cout << "0";
			}else if(it2 != p2.end()){
				cout << "1";
			}else{
				cout << "2";
			}
		}

		cout << "\n";
	}

	return 0;
}
