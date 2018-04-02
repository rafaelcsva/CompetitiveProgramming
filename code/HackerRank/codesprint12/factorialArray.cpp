#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 1000;
const int M = 100;
const int mod = (int) 1e9;
long long int pre[M], A[N];
int lazy[N << 3];

typedef struct{
	int fats[M];
}Tree;

Tree tree[N << 3];

long long int fat(int n){
	if(n >= 40)
		return 0;

	return pre[n];
}

void preCalc(){
	pre[0] = 1;

	for(int i = 1 ; i <= 39 ; i++){
		pre[i] = (pre[i - 1] * i) % mod;
		//cout <<i << ' ' << pre[i] << '\n';
	}
}

long long int sum(Tree a){
	long long int s = 0;

	for(int i = 0 ; i < 40 ; i++){
		//cout << i << ' ' << a.fats[i] << '\n';
		s = (s + a.fats[i] * fat(i)) % mod;
	}

	return s;
}

Tree join(Tree a, Tree b){
	Tree r;

	for(int i = 0 ; i < 40 ; i++){
		r.fats[i] = a.fats[i] + b.fats[i];
	}

	return r;
}

Tree next(Tree a, int node, int left, int right){
	lazy[left] += lazy[node];
	lazy[right] += lazy[node];

	int s = lazy[node];

	for(int i = 39 ; i >= 0 ; i --){
		a.fats[i] = 0;
		//cout << i << " = " << i - s << " " << a.fats[i] << " " <<a.fats[i - s] << '\n';
		if(i - s >= 0){		
			a.fats[i] = a.fats[i - s];
			a.fats[i - s] = 0;
		}
	}

	lazy[node] = 0;

	return a;
}

void build(int i, int j, int node){
	if(i == j){
		for(int k = 0 ; k < 40 ; k++){
			tree[node].fats[k] = 0;
		}

		if(A[i] < 40){
			tree[node].fats[A[i]] = 1;
		}
	}else{
		int left = node << 1;
		int right = node << 1 | 1;
		int mid = (i + j) / 2;

		build(i, mid, left);
		build(mid + 1, j, right);
		
		tree[node] = join(tree[left], tree[right]);	
	}
}

void update1(int i, int j, int ini, int end, int node){
	int left = node << 1;
	int right = node << 1 | 1;	

	if(lazy[node]){
		tree[node] = next(tree[node], node, left, right);
	}	

	if(i > end || j < ini){
		return;
	}	

	if(i >= ini && j <= end){
		lazy[node]++;

		tree[node] = next(tree[node], node, left, right);
	}else{
		int mid = (i + j) / 2;
		
		update1(i, mid, ini, end, left);
		update1(mid + 1, j, ini, end, right);

		tree[node] = join(tree[left], tree[right]);
	}
}

void update2(int i, int j, int indx, int node, int value){
	int left = node << 1;
	int right = node << 1 | 1;

	if(lazy[node]){
		tree[node] = next(tree[node], node, left, right);
	}	

	if(i > indx || j < indx)
		return;	
	
	if(i == j){
		for(int i = 0 ; i < 40 ; i++){
			tree[node].fats[i] = 0;
		}

		if(value < 40)
			tree[node].fats[value] = 1;
	}else{
		int mid = (i + j) / 2;

		update2(i, mid, indx, left, value);
		update2(mid + 1, j, indx, right, value);

		tree[node] = join(tree[left], tree[right]);
	}
}

Tree query(int i, int j, int ini, int end, int node){
	int left = node << 1;
	int right = node << 1 | 1;
	

	if(lazy[node]){	
	//	cout << lazy[node] << "value || nodes ";
	//	cout << i << ' ' << j << " lazy\n"; 
		tree[node] = next(tree[node], node, left, right);	
	}
	
	if(i > end || j < ini){
		Tree error;
		error.fats[1] = -1;
		
		return error;
	}
	
	if(i >= ini && j <= end){
		

		return tree[node];
	}else{
		
		int mid = (i + j) / 2;

		Tree a = query(i, mid, ini, end, left);
		Tree b = query(mid + 1, j, ini, end, right);
		
		if(a.fats[1] == -1){
			return b;
		}

		if(b.fats[1] == -1){
			return a;
		}

		return join(a, b);
	}
}

int main (){
	int n, m;
	preCalc();
	//cout << pre[5] << '\n';
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}

	build(1, n, 1);

	while(m--){
		int op, l, r;

		cin >> op >> l >> r;

		if(op == 1){
			update1(1, n, l, r, 1);
		}else if(op == 2){
			Tree resp = query(1, n, l, r, 1);
	
			cout << sum(resp) << '\n';
		}else{
			update2(1, n, l, 1, r);
		}
	}		

	return 0;

}
