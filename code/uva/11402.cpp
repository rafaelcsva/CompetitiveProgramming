#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;
int tree[N << 4];
int lazy[N << 4];
string land, part;

void build(int l, int r, int node){
	lazy[node] = 0;

	if(l == r){
		tree[node] = land[l] == '1' ? 1 : 0;
		//cout << l << " = " ;
		//cout << tree[node] << ' ';
		//cout << land[l] << '\n';
	}else{
		int left = node << 1;
		int right = node << 1 | 1;
		int mid = (l + r) / 2;

		build(l, mid, left);
		build(mid + 1, r, right);

		tree[node] = tree[left] + tree[right];

		//cout << l << ' ' << r << " -> " << tree[node] << '\n';
	}
}

void apply(int node){
	int left = node << 1;
	int right = node << 1 | 1;

	if(lazy[left] == 1){
		lazy[left] = 2;
	}else if(lazy[left] == 2){
		lazy[left] = 1;
	}else if(lazy[left] == 3){
		lazy[left] = 0;
	}else{
		lazy[left] = 3;
	}

	if(lazy[right] == 1){
		lazy[right] = 2;
	}else if(lazy[right] == 2){
		lazy[right] = 1;
	}else if(lazy[right] == 3){
		lazy[right] = 0;
	}else{
		lazy[right] = 3;
	}
}

void next(int node, int i, int j){
	int left = node << 1;
	int right = node << 1 | 1;
	int p = lazy[node];
	//cout << i << ' ' << j << " before = " << tree[node] ;
	if(p == 3){
		apply(node);

		tree[node] = (j - i + 1) - tree[node];
	}else{
		if(p == 1){
			tree[node] = j - i + 1;
		}else{
			tree[node] = 0;
		}
	
		lazy[left] = lazy[right] = p;
	}
	//cout << "after = " << tree[node] << '\n';
	lazy[node] = 0;
}

void update(int l, int r, int L, int R, int node, int type){
	if(lazy[node]){
		next(node, l, r);
	}
	
	if(l > R || r < L){
		return;
	}

	if(l >= L && r <= R){
		lazy[node] = type;
		
		next(node, l, r);

	}else{
		int left = node << 1;
		int right = node << 1 | 1;
		int mid = (l + r) / 2;

		update(l, mid, L, R, left, type);
		update(mid + 1, r, L, R, right, type);	

		tree[node] = tree[left] + tree[right];	
	}
}

int query(int l, int r, int L, int R, int node){
	if(lazy[node]){
		next(node, l, r);
	}
	
	if(l > R || r < L){
		return 0;
	}

	if(l >= L && r <= R){
		return tree[node];
	}else{
		int left = node << 1;
		int right = node << 1 | 1;
		int mid = (l + r) / 2;

		int a = query(l, mid, L, R, left);
		int b = query(mid + 1, r, L, R, right);

		return a + b;
	}
}

int main (){
	int t;

	ios::sync_with_stdio(false);

	cin >> t;

	for(int k = 1 ; k <= t ; k++){
		land = " ";

		int m;
		int n = 0;

		cin >> m;
		
		cout << "Case " << k << ":\n";
			
		for(int i = 0 ; i < m ; i++){
			int p;
	
			cin >> p;
	
			cin >> part;

			while(p--){
				land += part;
			}
		}
	
		n = land.length() - 1;
	//	cout << land[1] << '\n';
		build(1, n, 1);

		int q;

		cin >> q;

		int c = 1;

		while(q--){
			char op;
			int a, b;

			cin >> op >> a >> b;
	
			a++;
			b++;

			if(op == 'F'){
				update(1, n, a, b, 1, 1);
			}else if(op == 'E'){
				update(1, n, a, b, 1, 2);
			}else if(op == 'I'){
				update(1, n, a, b, 1, 3);
			}else{
				cout << "Q" << c << ": " << query(1, n, a, b, 1) << '\n';
				c++;
			}
		}

	}

	return 0;
}
