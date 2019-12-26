#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b){
	return a * (b / __gcd(a, b));
}

int cnt(int a){
	int d = 0;

	while(a % 2 == 0){
		d++;
		a /= 2;
	}

	return d;
}

int main(){
	for(int i = 1 ; i <= 1000 ; i++){
		for(int j = 1 ; j <= 1000 ; j++){
			int g = lcm(i, j);

			int q = g / i;
			int d = g / j;

			if(((q + d) & 1) == 0){
				assert(cnt(i) == cnt(j));
				printf("%d (%d, %d)\n", __gcd(i, j), i, j);
			}
		}
	}

}