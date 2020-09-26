#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;

int r = -1;
const int N = int(1e4 + 10);
pii seg[N];

int main(){
	int l, g;

	while(scanf("%d %d", &l, &g) != EOF){
		if(l == 0 && g == 0) break;

		for(int i = 0 ; i < g ; i++){
			int xi, ri;

			scanf("%d %d", &xi, &ri);

			seg[i] = {max(0, xi - ri), min(l, xi + ri)};
		}

		sort(seg, seg + g);

		int r = 0;
		int i = 0;
		int taked = 0;

		while(i < g && r < l){
			int j = i;
			int de = -1;

			while(j < g && seg[j].first <= r){
				de = max(de, seg[j].second);
				j++;
			}

			if(de == -1){
				break;
			}else{
				r = de;
				taked++;
				i = j;
			}
		}

		if(r < l){
			printf("-1\n");
		}else{
			printf("%d\n", g - taked);
		}
	}

	return 0;
}