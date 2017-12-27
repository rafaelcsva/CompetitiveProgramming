#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];
bitset<N>mark;

void solve(int k, int n, int x){
	for(int i = x ; i < n ; i++){
		if(mark[i] == 0 && a[i] >= k){
			mark[i] = 1;
			solve(k + 1, n, i + 1);
			break;
		}
	}
}

int main (){
	int n;	

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int cur = 0;
	int act = 0;

	for(int i = 0 ; i < n ; i++){
		if(mark[i] == 1){
			continue;
		}

		act++;
			
		solve(1, n, i + 1);			
	}

	printf("%d\n", act);

	return 0;
}
