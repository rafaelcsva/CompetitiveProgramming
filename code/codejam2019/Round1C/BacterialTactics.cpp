#include <bits/stdc++.h>

using namespace std;

const int N = 20;
string tab[N];
bool marked[N][N], fob_h[N][N], fob_v[N][N];
int n, m;

bool ok(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m && !marked[i][j] && tab[i][j] == '.';
}

void dfs_vertical(int i, int j){
	if(!ok(i, j)){
		return;
	}

	marked[i][j] = true;
	dfs_vertical(i + 1, j);
}

void dfs_horizontal(int i, int j){
	if(!ok(i, j)){
		return;
	}

	marked[i][j] = true;
	dfs_horizontal(i, j + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int ts = 1;

	cin >> t;

	while(t--){

		cin >> n >> m;

		for(int i = 0 ; i < n ; i++){
			cin >> tab[i];
		}

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(tab[i][j] == '#'){
					for(int k = 0 ; k < m ; k++){
						fob_h[i][k] = true;
					}

					for(int k = 0 ; k < n ; k++){
						fob_v[k][j] = true;
					}
				}
			}
		}

		int comp = 0;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(!ok(i, j)){
					continue;
				}
				// cout << i << " , " << j << endl;
				if(ok(i + 1, j) && !fob_v[i][j]){
					comp++;
					dfs_vertical(i, j);
				}else if(!fob_h[i][j]){
					comp++;
					dfs_horizontal(i, j);
				}
			}
		}

		memset(marked, false, sizeof marked);

		cout << "Case #" << ts++ << ": " ;
		// cout << comp << endl;

		if((comp & 1) == 0){
			cout << 0 << endl;
		}else{
			int ans = 0;

			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++){
					if(ok(i, j)){
						// cout << i << " " << j << endl;
						if(!fob_h[i][j]){
							ans++;
						}

						if(!fob_v[i][j]){
							ans++;
						}
					}
				}
			}

			cout << ans << endl;
		}

		memset(fob_h, false, sizeof fob_h);
		memset(fob_v, false, sizeof fob_v);
	}

	return 0;
}