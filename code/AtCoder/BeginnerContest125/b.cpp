#include <bits/stdc++.h>

using namespace std;

int v[100], c[100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}

	for(int i = 0 ; i < n ; i++){
		cin >> c[i];
	}

	int sum = 0;
	

	for(int i = 0 ; i < n ; i++){
		sum += max(0, v[i] - c[i]);
	}

	cout << sum << endl;

	return 0;
}