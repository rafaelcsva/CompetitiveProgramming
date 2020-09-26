#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll mod = 1e9 + 7;
const int N = mod + 10;

unordered_map< int, vector< int > > adj, rev, adj1, rev1;
unordered_map< int, double > f, f1;
unordered_map< int, int > self;
unordered_map< int, int > self1;
unordered_map< int, int > cnt;
unordered_map< int, int > cnt1;

int get_hash(vector< int > &v){
	ll d = 1;
	ll ans = 0LL;
	const ll b = ll(1e5) + 49;

	for(int i = 0 ; i < v.size() ; i++){
		ans += v[i] * d;
		d *= b;
		
		d %= mod;
		ans %= mod;
	}

	return ans;
}

int main(){
	for(int i = 2 ; i * i < mod ; i++){
		if(mod % i == 0){
			assert(false);
		}
	}

	int te;

	scanf("%d", &te);

	while(te--){
		int n;

		scanf("%d", &n);

		vector< int > t, vv;
		
		for(int i = 0 ; i < n ; i++){
			int xi;

			scanf("%d", &xi);

			t.push_back(xi);
		}

		vv = t;

		sort(vv.begin(), vv.end());

		int u = get_hash(vv);

		f[u] = 0.0;
		f1[u] = 0.0;

		do{
			int u = get_hash(vv);
			
			vector< int > tmp = vv;

			for(int i = 0, j = 1 ; j < vv.size() ; i++, j++){
				if(vv[i] > vv[j]){
					swap(tmp[i], tmp[j]);

					int v = get_hash(tmp);

					adj[u].push_back(v);
					rev[v].push_back(u);

					swap(tmp[i], tmp[j]);
				}else{
					self[u]++;
				}
			}

			for(int i = 0 ; i < vv.size() ; i++){
				for(int j = 0 ; j < vv.size() ; j++){
					int ii = min(i, j);
					int jj = max(i, j);

					if(vv[ii] > vv[jj]){
						swap(tmp[ii], tmp[jj]);

						int v = get_hash(tmp);

						adj1[u].push_back(v);
						rev1[v].push_back(u);

						swap(tmp[ii], tmp[jj]);
					}else{
						self1[u]++;
					}
				}
			}

		}while(next_permutation(vv.begin(), vv.end()));
		
		//--estrategia Carlos--//

		queue< int > q;

		for(int a: rev[u]){
			cnt[a]++;

			if(cnt[a] == adj[a].size()){
				q.push(a);
			}
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();

			for(int a: rev[u]){
				cnt[a]++;

				if(cnt[a] == adj[a].size()){
					q.push(a);
				}
			}

			int q = self[u] + adj[u].size();

			double s = 0.0;

			for(int a: adj[u]){
				s += f[a];
			}

			f[u] = (q + s) / (q - self[u]);
		}

		//--estrategia Monty--//

		for(int a: rev1[u]){
			cnt1[a]++;

			if(cnt1[a] == adj1[a].size()){
				q.push(a);
			}
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();

			for(int a: rev1[u]){
				cnt1[a]++;

				if(cnt1[a] == adj1[a].size()){
					q.push(a);
				}
			}

			int q = self1[u] + adj1[u].size();

			double s = 0.0;

			for(int a: adj1[u]){
				s += f1[a];
			}

			f1[u] = (q + s) / (q - self1[u]);
		}

		int uu = get_hash(t);

		printf("Monty %.6lf Carlos %.6lf\n", f1[uu], f[uu]);

		adj.clear();
		adj1.clear();
		rev.clear();
		rev1.clear();
		self1.clear();
		self.clear();
		f1.clear();
		f.clear();
		cnt.clear();
		cnt1.clear();

		t.clear();
	}

	return 0;
}