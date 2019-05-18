#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
vector< int > segtree[3][N << 2];
int a[3][N];
char s[N];
int f[N];

void build(int node, int ii, int jj, int idx){
	if(ii == jj){
		segtree[idx][node].push_back(a[idx][ii]);
	}else{
		int mid = (ii + jj) >> 1;
		int lf = node << 1;
		int rg = lf + 1;

		build(lf, ii, mid, idx);
		build(rg, mid + 1, jj, idx);

		int i = 0, j = 0;

		while(i < segtree[idx][lf].size() && j < segtree[idx][rg].size()){
			int u = segtree[idx][lf][i];
			int v = segtree[idx][rg][j];

			if(u < v){
				segtree[idx][node].push_back(u);
				i++;
			}else{
				segtree[idx][node].push_back(v);
				j++;
			}
		}

		while(i < segtree[idx][lf].size()){
			segtree[idx][node].push_back(segtree[idx][lf][i]);
			i++;
		}

		while(j < segtree[idx][rg].size()){
			segtree[idx][node].push_back(segtree[idx][rg][j]);
			j++;
		}
	}
}

int query(int node, int i, int j, int l, int r, int idx){
	// printf("%d %d\n", i, j);
	if(i > r || j < l){
		return 0;
	}

	if(l <= i && j <= r){
		return upper_bound(segtree[idx][node].begin(), segtree[idx][node].end(), r) - lower_bound(segtree[idx][node].begin(), segtree[idx][node].end(), l);
	}else{
		int mid = (i + j) >> 1;
		int lf = node << 1;
		int rg = lf + 1;

		return query(lf, i, mid, l, r, idx) + query(rg, mid + 1, j, l, r, idx);
	}
}

stack< int > st1, st2;
char str[N];

int main(){
	int n;

	scanf("%d", &n);

	scanf("\n%s", str);

	n = strlen(str);

	for(int i = 1 ; i <= n ; i++){
		char ci = str[i - 1];

		if(ci == '('){
			st1.push(i);
		}else if(ci == ')'){
			if(st1.size()){
				a[0][i] = st1.top();
				st1.pop();
			}
		}else if(ci == '['){
			st2.push(i);
		}else if(ci == ']'){
			if(st2.size()){
				a[1][i] = st2.top();
				st2.pop();
			}
		}
	}

	build(1, 1, n, 0);
	build(1, 1, n, 1);

	int q;

	scanf("\n%d", &q);

	while(q--){
		int l, r;

		scanf("%d %d", &l, &r);

		printf("%d %d\n", query(1, 1, n, l, r, 0), query(1, 1, n, l, r, 1));
	}

	return 0;
}	