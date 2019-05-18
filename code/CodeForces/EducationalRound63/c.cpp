#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
const int N = int(1e6);
ll x[N];
ll p[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for(int i = 0 ; i < n ; i++){
		cin >> x[i];
	}

	for(int j = 0 ; j < m ; j++){
		cin >> p[j];
	}

	ll g = 0LL;

	for(int i = 1 ; i < n ; i++){
		g = __gcd(x[i] - x[i - 1], g);
	}

	int idx = -1;

	for(int i = 0 ; i < m ; i++){
		if(g % p[i] == 0LL){
			idx = i + 1;
			break;
		}
	}

	if(idx != -1){
		cout << "YES" << endl;
		cout << x[0] << " " << idx << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}