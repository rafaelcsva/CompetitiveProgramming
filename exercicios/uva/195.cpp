#include <bits/stdc++.h>

using namespace std;

bool compar(string a, string b){
	int d = 32;

	for(int i = 0 ; i < a.length() ; i++){
		char c1 = a[i] | d;
		char c2 = b[i] | d;
		
		if(c1 > c2)
			return false;

		if(c1 < c2)
			return true;

		if(a[i] < b[i]){
			return true;
		}

		if(a[i] > b[i])
			return false;
	}

	return true;
}

int main (){
	int t;
	string s;
	vector<string>r;

	cin >> t;
	
	while(t--){
		cin >> s;
		sort(s.begin(), s.end());

		do{
			r.push_back(s);
		}while(next_permutation(s.begin(), s.end()));

		sort(r.begin(), r.end(), compar);

		for(int i = 0 ; i < r.size() ; i++){
			char c = '\n';
			cout << r[i] << c;
		}	
	
		r.clear();
	}

	return 0;
}
