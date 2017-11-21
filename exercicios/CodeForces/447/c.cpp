#include <bits/stdc++.h>

using namespace std;

const int N = 4100;
int a[4100];

int main (){
	int n;

	set<int>st;
	set<int>::iterator it;
	set<int>::iterator it1;
	
	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		st.insert(a[i]);
	}

	for(int i = 0 ; i < st.size() ; i++){
		int gcd = a[i];

		for(int j = i + 1; j < st.size() ; j++){
			gcd = __gcd(gcd, a[j]);

			if(st.find(gcd) == st.end()){
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << n << '\n';

	for(int i = 0 ; i < n ; i++){
		cout << a[i];

		if(i < n-1)
			cout << " ";
	}

	cout << '\n';
}
