#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int pref, suf, opt;
}SegmentTree;

const int N = 100010;
SegmentTree segtree[N << 4];
int v[N];

SegmentTree NewSegTree(){
	SegmentTree ret;

	ret.pref = ret.suf = ret.opt = 1;

	return ret;
}

SegmentTree join(int lf,int rg, SegmentTree l, SegmentTree r){
	int mid = (lf + rg) / 2;
	
	SegmentTree ret;

	ret.pref = l.pref;
	ret.suf = r.suf;
	
	ret.opt = max(l.opt, r.opt);

	if(v[mid] == v[mid + 1]){
		ret.opt = max(l.suf + r.pref, ret.opt);
	}

	if(v[lf] == v[mid + 1]){
		ret.pref += r.pref;
	}

	if(v[rg] == v[mid]){
		ret.suf += l.suf;
	}

	return ret;
}

void Build(int i, int j, int node){
	//cout << i << ' ' << j << ' ' << node << '\n';
	if(i == j){
		segtree[node] = NewSegTree();
	}else{
		int left = node << 1;
		int right = node << 1 | 1;
		int mid = (i + j) / 2;

		Build(i, mid, left);
		Build(mid + 1, j, right);

		//cout << "left = " << i << " right = " << j << '\n';
		segtree[node] = join(i, j, segtree[left], segtree[right]);	
	}
}

SegmentTree SegTreeError(){
	SegmentTree error;
		
	error.pref = -1;

	return error;
}

SegmentTree Query(int i, int j, int l, int r, int node){

	if(i > r || j < l){
		return SegTreeError();
	}

	int left = node << 1;
	int right = node << 1 | 1;

	if(i >= l && j <= r){
		//cout << i << ' ' << j << ' ' << node << '\n';
		return segtree[node];
	}else{
		int mid = (i + j) / 2;

		SegmentTree lf = Query(i, mid, l, r, left);
		SegmentTree rg = Query(mid + 1, j, l, r, right);

		if(lf.pref == -1){
			return rg;
		}	

		if(rg.pref == -1){
			return lf;
		}

		return join(i, j, lf, rg);
	}
}

int main (){
	int n, q;

	while(scanf("%d", &n) != EOF){
		if(n == 0)
			break;
	
		scanf("%d", &q);

		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &v[i]);
		}

		Build(1, n, 1);

		for(int i = 0 ; i < q ; i++){
			int l, r;
	
			scanf("%d%d", &l, &r);
	
			printf("%d\n", Query(1, n, l, r, 1).opt);
		}		
	}
	
	return 0;
}
