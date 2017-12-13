#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
long long int calc[2 * N + 10];
long long int used[2 * N + 10];
long long int pre[N];

long long int sum(long long int num){
	if(used[num])
		return calc[num];

	used[num] = 1;

	string s = to_string(num);
	long long int sumod = 0, sumeven = 0;

	for(long long int i = 0 ; i < s.length() ; i++){
		long long int a = s[i] - '0';

		if(a % 2 == 0)
			sumeven += a;
		else
			sumod += a;
	}

	return calc[num] = abs(sumeven - sumod);
}


int main (){
	int t;
	long long int temp = 0;

	pre[1] = temp = 2;
	
	for(long long int i = 2 ; i <= N ; i++){
		long long int a = sum(2 * i);
		long long int b = sum(i);
		long long int c = sum(2 * i - 1);

		temp += -b + c + a;
	
		pre[i] = pre[i - 1] + 2 * temp - a; 		
						
	}
 
	scanf("%d", &t);
	
	while(t--){
		long long int n;

		scanf("%lli", &n);
		
		printf("%lli\n", pre[n]);
	}

	return 0;
}
