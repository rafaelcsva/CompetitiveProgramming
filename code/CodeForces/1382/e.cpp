#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];
int b[N];
set< int > mst;
map< int, int > cnt;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, x, y;

		scanf("%d %d %d", &n, &x, &y);

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);

			if(i < y){
				mst.insert(a[i]);
				cnt[a[i]]++;
			}
		}

		int fnd = -1;

		for(int i = 1 ; i <= n + 1 ; i++){
			if(mst.find(i) == mst.end()){
				fnd = i;
			}
		}

		cnt[fnd] = n - y;

		if(cnt[fnd] != 0)
			mst.insert(fnd);

		bool ok = true;

		for(int i = 0 ; i < n ; i++){
			if(i < x){
				b[i] = a[i];
				auto u = mst.find(b[i]);
				cnt[b[i]]--;

				if(cnt[b[i]] == 0){
					mst.erase(b[i]);
				}
			}else{
				auto y = *mst.begin();
				auto t = *mst.rbegin();

				if(y == a[i] && t == a[i]){
					ok = false;
					break;
				}else{
					if(y == fnd){
						swap(y, t);
					}

					if(y != a[i]){
						b[i] = y;

						cnt[y]--;

						if(cnt[y] == 0){
							mst.erase(y);
						}
					}else{
						b[i] = t;

						cnt[t]--;

						if(cnt[t] == 0){
							mst.erase(t);
						}
					}
				}
			}

			// printf("%d ", b[i]);
		}

		if(ok){
			printf("YES\n");

			for(int i = 0 ; i < n ; i++){
				printf("%d ", b[i]);
			}

			printf("\n");
		}else{
			printf("NO\n");
		}

		cnt.clear();
		mst.clear();
	}

	return 0;
}