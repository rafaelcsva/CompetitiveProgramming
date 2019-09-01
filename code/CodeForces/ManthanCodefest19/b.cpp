#include <bits/stdc++.h>

using namespace std;

const int N = int(2e3 + 10);
int a[N];
int n;

bool solve(int l, int r){
	set< int > st;

	for(int i = 0 ; i < n ; i++){
		if(l <= i && i <= r) continue;

		if(st.find(a[i]) != st.end()) return false;

		st.insert(a[i]);
	}

	return true;
}

bool can(int mid){
	for(int i = 0 ; i <= n - mid ; i++){
		if(solve(i, i + mid - 1)){
			return true;
		}
	}

	return false;
}

int main(){
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}

	int lo = 0, hi = n;
	int r = -1;

	while(lo <= hi){
		int mid = (lo + hi) >> 1;

		if(can(mid)){
			hi = mid - 1;
			r = mid;
		}else{
			lo = mid + 1;
		}
	}

	printf("%d\n", r);

	return 0;
}