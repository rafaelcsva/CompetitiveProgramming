#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
int con[N];

int main(){
	int n;

	scanf("%d", &n);

	int st = 1, en = 0;

	for(int i = 0 ; i < n ; i++){
		int ai;

		scanf("%d", &ai);

		int lo = st;
		int hi = en;
		int r = -1;

		while(lo <= hi){
			int mid = (lo + hi) >> 1;

			if(con[mid] < ai){
				r = mid;
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}

		if(r == -1){
			en++;
			con[en] = ai;
		}else{
			con[r] = ai;
		}
	}

	printf("%d\n", en - st + 1);

	return 0;
}