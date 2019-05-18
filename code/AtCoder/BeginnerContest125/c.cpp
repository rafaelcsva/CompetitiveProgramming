#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6);
int pref[N];
int suf[N];
int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}

	for(int i = 1 ; i <= n ; i++){
		pref[i] = __gcd(a[i], pref[i - 1]);
	}

	for(int i = n ; i >= 1 ; i--){
		suf[i] = __gcd(a[i], suf[i + 1]);
	}

	int best = 0;

	for(int i = 1 ; i <= n ; i++){
		best = max(best, __gcd(pref[i - 1], suf[i + 1]));
	}

	cout << best << endl;

	return 0;
}