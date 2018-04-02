#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int fib[N];
bool ver[N];

int main (){
	int n;
	
	cin >> n;
	
	fib[0] = 0;
	fib[1] = 1;
	
	int i = 1;
	
	while(fib[i] <= 10100){
		ver[fib[i]] = true;
		fib[i + 1] = fib[i] + fib[i - 1];
		cout << fib[i] << '\n';
		i++;
	}
	
	for(int i = 0 ; i < n ; i++){
		if(ver[i + 1]){
			cout << 'O';
		}else{
			cout << 'o';
		}
	}
	cout << '\n';
	return 0;
}
