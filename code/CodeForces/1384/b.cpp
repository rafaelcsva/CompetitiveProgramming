#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;
int a[N];
int  r[N];
int n, k, l;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		bool ok = true;

		scanf("%d %d %d", &n, &k, &l);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
			
			if(a[i] > l){
				ok = false;
			}
		}

		if(!ok){
			printf("No\n");
		}else{
			for(int i = 0 ; i < n ; i++){
				r[i] = min(k, l - a[i]);
			}

			int d = r[0];
			int dec = 1;

			for(int i = 0 ; i < n ; i++){
				if(d > r[i]){
					ok = false;
					break;
				}

				if(r[i] == k){
					d = r[i + 1];
					dec = 1;
				}else{
					if(d == 0 || !dec){
						dec = 0;
						d++;
					}else{
						d--;
						d = min(d, r[i + 1]);
					}
				}
			}

			if(ok){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}

	return 0;
}