#include <bits/stdc++.h>

#define lli	long long int
using namespace std;


int main (){
	lli n;
	ios::sync_with_stdio(false);

	cin >> n;

	int op1 = 1, op2 = 0;
	int ini = 1, mark = -1;
	vector<int> v;
	
	if(n == 1){
		cout << "1\n1 1\n";
		return 0;
	}
	if(n == 3){
		cout << "0\n1 3\n";
		return 0;
	}

	int tmp = n / 2;

	if(n % 2){
		v.push_back(3);
		tmp = (n - 3) / 2;
		ini = 4;		
	}
	
	for(int i = ini ; i <= (n - ini) / 2 + ini ; i++){
		if(op1){
			v.push_back(i);
			v.push_back(n - i + ini);
		}
		swap(op1, op2);
	}

	lli sum = 0;

	for(int i = 0 ; i < v.size() - tmp % 2 ; i++){
		sum += v[i];		
	}

	cout << abs((((1 + n) * n) / 2 - ((lli)2) * sum)) << '\n';
	cout << v.size() - tmp % 2;

	for(int i = 0 ; i < v.size() - tmp % 2 ; i++){
		cout << ' ' << v[i];
	}
	
	cout << '\n';

	return 0;
}
