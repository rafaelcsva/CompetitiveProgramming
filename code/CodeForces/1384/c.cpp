#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
set< pair< char, char > > st;
set< char > con[30];
int vis[N];
int father[N];
int test = 1;

int find(int x){
	if(x == father[x]){
		return x;
	}

	return father[x] = find(father[x]);
}

void join(int a, int b){
	int x = find(a);
	int y = find(b);

	if(x != y){
		if(x > y){
			father[x] = y;
		}else{
			father[y] = x;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		int n;

		for(int i = 0 ; i < 30 ; i++){
			father[i] = i;
		}
		cin >> n;

		string a, b;

		cin >> a >> b;

		bool ok = true;

		for(int i = 0 ; i < n ; i++){
			if(a[i] > b[i]){
				ok = false;
				break;
			}else if(a[i] != b[i]){
				st.insert({a[i], b[i]});
				// con[a[i] - 'a'].insert(b[i]);
			}
		}

		if(ok){
			int ans = 0;

			for(auto u: st){
				int a = u.first - 'a';
				int b = u.second - 'a';

				if(find(a) != find(b)){
					ans++;
					join(a, b);
				}
			}

			printf("%d\n", ans);
		}else{
			printf("-1\n");
		}

		st.clear();
		for(int i = 0 ; i < 30 ; i++) father[i] = i;
	}

	return 0;
}