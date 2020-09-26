#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-13;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;
		long long d;

		scanf("%d %lld", &n, &d);

		int cnt = 0;
		for(int i = 0 ; i < n ; i++){
			long long vi, fi, ci;

			scanf("%lld %lld %lld", &vi, &fi, &ci);

			double cons = d * ci / vi;
			
			if(fi * vi < d * ci){
				continue;
			}

			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}