#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int n;

int build[N];

bool can(int mid){
	if(mid == 0){
		for(int i = 0 ; i < n ; i++){
			build[i] = a[i];
		}

		return true;
	}

	if(a[mid - 1] == a[n - 1]){
		return false;
	}

	for(int j = 0, i = 1 ; j < mid ; j++, i += 2){
		build[i] = a[j];
	}

	build[mid * 2] = a[n - 1];

	// for(int i = 0 ; i <= mid * 2 + 1 ; i++){
	// 	printf("%d ", build[i]);
	// }

	// printf("\n");

	vector< int > uns;

	int st = mid;
	int j = 0;

	while(j < mid){
		while(st < n - 1 && a[st] == a[j]){
			uns.push_back(a[st]);
			st++;
		}

		if(st == n - 1){
			return false;
		}

		int pos = 1 + j * 2;

		build[pos - 1] = a[st];
		// printf("%d recebe %d\n", pos - 1, a[st]);
		j++;
		st++; 
	}
	// printf("%d, %d\n", j, st);

	// for(int i = 0 ; i <= mid * 2 + 1 ; i++){
	// 	printf("%d ", build[i]);
	// }

	// printf("\n");
	int i;
	for(i = mid * 2 + 1, j = st ; j < n - 1 ; j++, i++){
		build[i] = a[j];
	}
	j = 0;
	for(; i < n ; i++){
		build[i] = uns[j];
		j++;
	}

	return true;
}

int main(){
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	if(n <= 2){
		printf("0\n");
		can(0);
	}else{
		int lo = 1, hi = (n - 1) / 2;
		int r = 0;

		while(lo <= hi){
			int mid = (lo + hi) >> 1;

			if(can(mid)){
				r = mid;
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}

		can(r);

		printf("%d\n", r);
	}

	for(int i = 0 ; i < n ; i++){
		printf("%d ", build[i]);
	}

	printf("\n");

	return 0;
}