#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 100);
int a[N];
int dpL[N], dpR[N];
int mp[N];

int main (){
	int n, m;

	cin >> n >> m;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		mp[i] = i;
	}

	for(int i = 1 ; i < n ; i++){
		if(a[i] >= a[i - 1]){
			dpL[i] = 1 + dpL[i - 1];
			mp[i - dpL[i]] = i; 
		}
	}

	for(int i = n - 2 ; i >= 0 ; i--){
		if(a[i] >= a[i + 1]){
			dpR[i] = 1 + dpR[i + 1];
		}
	}

	while(m--){
		int l, r;

		cin >> l >> r;
		l--, r--;
		
		int m = mp[l - dpL[l]];

		if(m > r){
			cout << "Yes" << endl;
			continue;
		}

		if(m - dpL[m] <= l && m + dpR[m] >= r){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}

	return 0;
}