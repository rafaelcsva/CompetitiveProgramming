#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define ff first
#define ss second
#define pb push_back

const int N = 5005;
int n, q;
int ft[N];

void upd(int id, int v){
	while(id < N){
		ft[id] += v;
		id += id & (-id);
	}
}

void add(int l, int r){
	upd(l, 1);
	upd(r + 1, -1);
}

int qry(int id){
	int ret = 0;
	while(id){
		ret += ft[id];
		id -= id & (-id);
	}
	return ret;
}

int psum[N][3];

int main(){
	ii v[N];
	scanf("%d %d", &n, &q);
	for(int i = 0; i < q; i++){
		scanf("%d %d", &v[i].ff, &v[i].ss);
		add(v[i].ff, v[i].ss);
	}
	int val[N];
	int sum = 0;
	for(int i = 1; i <= n; i++){
		val[i] = qry(i);
		sum += int(val[i] > 0);
	}
	for(int i = 1; i <= n; i++){
		psum[i][1] = psum[i-1][1] + int(val[i] == 1);
		psum[i][2] = psum[i-1][2] + int(val[i] == 2);
	}
	
	int ans = 0;
	for(int i = 0; i < q; i++){
		for(int j = i + 1; j < q; j++){
			int l1, r1;
			tie(l1, r1) = v[i];
			int l2, r2;
			tie(l2, r2) = v[j];
			int aux = (psum[r1][1] - psum[l1-1][1]) + (psum[r2][1] - psum[l2 - 1][1]);
			int l3 = max(l1, l2);
			int r3 = min(r1, r2);
			if(r3 >= l3){
				aux += psum[r3][2] - psum[l3 - 1][2];
			}
			ans = max(ans, sum - aux);
		}
	}


	printf("%d\n", ans);
	return 0;
}