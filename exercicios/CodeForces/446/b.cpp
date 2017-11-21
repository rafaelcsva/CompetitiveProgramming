#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
int mp[N];

int main(){
	int pos = -1;
	int r = 0;
	int n;
	int l;

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> l;

		mp[i] = l;
	}

	pos = max((int)0, n - 1 - mp[n - 1]);

	for(int i = n - 2 ; i >= 0 ; i--){
		if(i >= pos){
			r++;
		}
		int temp = max((int)0, i - mp[i]);

		if(temp < pos){
			pos = temp;
		}
	}

	cout << n - r << '\n';

	return 0;
}
