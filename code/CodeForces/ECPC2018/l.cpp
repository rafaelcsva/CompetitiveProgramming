#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
int segment[N << 3];
int lazzy[N << 3];

void shift(int node){
	int lf = node << 1;
	int rg = lf + 1;

	segment[node] *= -1;
	lazzy[lf] = !lazzy[lf];
	lazzy[rg] = !lazzy[rg];

	lazzy[node] = 0;
}

void build(int node, int i, int j){
	lazzy[node] = 0;

	if(i == j){
		segment[node] = 1;
	}else{
		int mid = (i + j) >> 1;
		int lf = node << 1;
		int rg = lf + 1;

		build(lf, i, mid);
		build(rg, mid + 1, j);
		segment[node] = segment[lf] + segment[rg];
	}
}

void update(int node, int i, int j, int l, int r){
	if(lazzy[node]){
		shift(node);
	}

	if(i > r || j < l){
		return;
	}

	if(l <= i && j <= r){
		lazzy[node] = !lazzy[node];
		shift(node);
	}else{
		int mid = (i + j) >> 1;
		int lf = node << 1;
		int rg = lf + 1;

		update(lf, i, mid, l, r);
		update(rg, mid + 1, j, l, r);

		segment[node] = segment[lf] + segment[rg];
	}
}

int query(int node, int i, int j, int l, int r){
	if(lazzy[node]){
		shift(node);
	}

	if(i > r || j < l){
		return 0;
	}

	if(l <= i && j <= r){
		return segment[node];
	}else{
		int mid = (i + j) >> 1;
		int lf = node << 1;
		int rg = lf + 1;

		return query(lf, i, mid, l, r) + query(rg, mid + 1, j, l, r);
	}
}

int main(){
	freopen("reflection.in", "r", stdin);
	
	int t;

	scanf("%d", &t);

	while(t--){
		build(1, 1, N);
		int q;

		scanf("%d", &q);

		while(q--){
			int xi;

			scanf("%d", &xi);

			if(xi == 0){
				printf("0\n");
				update(1, 1, N, 1, N);
			}else{
				printf("%d\n", query(1, 1, N, 1, xi));
				update(1, 1, N, xi + 1, N);
			}
		}
	}

	return 0;
}