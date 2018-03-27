#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = 1e5 + 100;
priority_queue<ll>pq;
ll v[N];

int main (){
	int n;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}

	ll tot = 0LL;
	
	for(int i = 0 ; i < n ; i++){
		ll t;
		
		pq.push(-v[i] - tot);
		
		cin >> t;
		
		tot += t;
		
		ll r = 0LL;
		
		while(!pq.empty() && (-pq.top()) <= tot){
			r += (-pq.top()) - (tot - t);
			pq.pop();
		}
		
		r += ((ll)pq.size()) * t; 
		
		cout << r << ' ';
	}

	cout << '\n';
	
	return 0;
}
