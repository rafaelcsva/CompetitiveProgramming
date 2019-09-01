#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6 + 10);
int a[N];
int b[N];
vector< int > balls;

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &a[i]);
	}

	for(int i = n ; i >= 1 ; i--){
		int cnt = 0;

		for(int k = i + i ; k <= n ; k += i){
			if(b[k]){
				cnt++;
			}
		}

		cnt = cnt & 1;

		if(cnt != a[i]){
			balls.push_back(i);
			b[i] = 1;
		}
	}

	printf("%lu\n", balls.size());

	for(int i = balls.size() - 1 ; i >= 0 ; i--){
		printf("%d\n", balls[i]);
	}

	return 0;
}