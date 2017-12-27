#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;
map<int, int>mp;

int main (){
	int n;
	int a[N];

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}

	if(n == 1){
		printf("-1\n");
		return 0;
	}

	sort(a, a+ n);

	if(n == 2){
		int r = a[1] - a[0];

		if(a[1] != a[0]){
			if(r % 2 == 0){

				printf("3\n");
				printf("%d %d %d\n", a[0] - r, a[0] + r / 2, a[1] + r);
			}else{
				printf("2\n");
				printf("%d %d\n", a[0] - r, a[1] + r);
			}
		}else{
			printf("1\n");
			printf("%d\n", a[0]);
		}

		return 0;
	}

	set<int>difs;
	bool flag = false;
	int cnt1 = 0, cnt2 = 0;
	int f = a[1] - a[0];

	for(int i = 1 ; i < n ; i++){
		difs.insert(a[i] - a[i - 1]);

		mp[a[i] - a[i - 1]]++;

		if(difs.size() > 2){
			printf("0\n");
			return 0;
		}
	}

	if(difs.size() == 2){
		int r = *(difs.begin());
		int m = *(difs.rbegin());

		for(int i = 1 ; i < n ; i++){
			if(a[i] - a[i - 1] != r){
				if(a[i] - (a[i - 1] + r) == r && mp[m] == 1){
					printf("1\n");
					printf("%d\n", a[i - 1] + r);
					return 0;
				}
			}else if(a[i] - a[i - 1] != m){
				if(a[i] - (a[i - 1] + m) == m && mp[r] == 1){
					printf("1\n");
					printf("%d %d\n", a[i - 1] + m, a[i - 1]);
					return 0;
				}
			}
		}

		printf("0\n");
		
	}else{
		int r = *(difs.begin());

		if(r == 0){
			printf("1\n");
	
			printf("%d\n", a[0]);
		}else{
			printf("2\n");
			printf("%d %d\n", a[0] - r, a[n - 1] + r);
		}
	}

	return 0;
}
