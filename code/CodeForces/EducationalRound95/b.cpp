#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int l[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}

		vector< int > v;

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &l[i]);

			if(l[i] == 0){
				v.push_back(a[i]);
			}
		}

		sort(v.begin(), v.end(), greater< int >());
		int j = 0;
		vector< int > ot;


		for(int i = 0 ; i < n ; i++){
			a[i] = (l[i] == 0 ? v[j++] : a[i]);
		}

		for(int i = 0 ; i < n ; i++){
			printf("%d ", a[i]);
		}

		printf("\n");
	}

	return 0;
}