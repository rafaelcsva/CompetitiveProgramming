#include <bits/stdc++.h>

using namespace std;

vector< int > v;

const int N = int(2e5) + 10;
long long arr[N];

int mod(int a, int n){
	return ((a % n) + n) % n;
}

int main(){
	int n;

	scanf("%d", &n);

	n *= 2;

	int a = 1;
	int b = 2;

	int p1 = 0;
	int p2 = n / 2;

	int taked = 0;

	while(taked != n){
		arr[p1] = a;
		arr[p2] = b;

		b += 2;
		a += 2;
		swap(a, b);

		taked += 2;

		p1 = (p1 - 1 + n) % n;
		p2--; 
	}

	// printf("YES\n");

	// for(int i = 0 ; i < n ; i++){
	// 	printf("%lld ", arr[i]);
	// }

	// printf("\n");

	long long sum1 = 0;

	for(int i = 0 ; i < n / 2 ; i++){
		sum1 += arr[i];
	}

	long long mn, mx;
	
	mn = mx = sum1;

	for(int i = 1 ; i < n ; i++){
		long long ret = arr[mod(i - 1, n)];
		long long add = arr[mod(i + n / 2 - 1, n)];

		long long nsum = sum1 - ret + add;

		mx = max(mx, nsum);
		mn = min(mn, nsum);

		sum1 = nsum;
	}

	if(mx - mn > 1){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

	for(int i = 0 ; i < n ; i++){
		printf("%lld ", arr[i]);
	}

	printf("\n");

	return 0;
}