#include <bits/stdc++.h>

using namespace std;

const int N = 5e4;
int mark[N];
bool enter[N];

bool can(int mid){
	int light = 0;
	int current = 0;

	for(int i = 0 ; i < N ; i++){
		if(enter[i]){
			light = i + mid ;
		}

		current += mark[i];

		if(current && light <= i){
			return false;
		}
	}

	return true;
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		int ti, tout;

		scanf("%d %d", &ti, &tout);

		mark[ti]++;
		enter[ti] = true;
		mark[tout]--;
	}

	int lo = 0, hi = N - 2;
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

	assert(r != -1);

	printf("%d\n", r);

	return 0;
}