#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5);
int a[N];

int lcm(int a, int b){
	return a * (b / __gcd(a, b));
}

int main(){
	int t;

	scanf("%d", &t);

	int n;
	
	while(t--){
		scanf("%d", &n);


		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		int sum = 0;

		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				sum += lcm(a[j], a[k]);
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}