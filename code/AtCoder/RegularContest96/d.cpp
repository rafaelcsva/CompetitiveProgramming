#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e5 + 10);
ll v[N], x[N];
ll suf[N];
ll segtree[N << 4];
ll INF = ll(1e17);

void build(int node, int i, int j){
	if(i == j){
		segtree[node] = suf[i];
	}else{
		int left = (node << 1);
		int right = left + 1;
		int mid = (i + j) / 2;
		
		build(left, i, mid);
		build(right, mid + 1, j);
		
		segtree[node] = max(segtree[left], segtree[right]);
	}
}

ll query(int node, int l, int r, int i, int j){
	if(i > r || j < l){
		return -INF;
	}
	
	if(i >= l && j <= r){
		return segtree[node];
	}else{
		int left = node << 1;
		int right = left + 1;
		int mid = (i + j) / 2;
		
		ll lft = query(left, l, r, i, mid);
		ll rgt = query(right, l, r, mid + 1, j);
		
		if(lft == -INF){
			return rgt;
		}else if(rgt == -INF){
			return lft;
		}
		
		return max(rgt, lft);
	}
}

int main (){
	ll n, c;
	
	cin >> n >> c;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i] >> v[i];
	}
	
	ll tot = c - x[n];
	ll gain = v[n];
	
	suf[n] = v[n] - (c - x[n]);
	
	for(int i = n - 1 ; i >= 1 ; i--){
		suf[i] = v[i];
		gain += v[i];
	}			
	cout << "n = " << suf[n] << endl;
	for(int i = n - 1 ; i >= 1 ; i--){
		suf[i] += suf[i + 1] - (x[i + 1] - x[i]);
		
		cout << i << ' ' << suf[i] << endl;
	}

	build(1, 1, n);

	ll resp = 0LL;
	ll sum = 0LL;
	
	for(int i = 0 ; i <= n ; i++){
		ll c = 0LL;
		
		sum += v[i];
		
		if(i != 0){
			sum -= x[i] - x[i - 1];
		}
		
		if(i != n){
			c = query(1, i + 1, n, 1, n);
		}
		
		cout << sum << ' ' << i + 1 << ' ' << n << ' ' << c << " max = " << max(sum + c - x[i], sum) << ' ' << x[i] << endl;
		
		resp = max(resp, max(sum + c - x[i], sum));
	}
	
	cout << resp << endl;
	
	return 0;
}
