#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
typedef pair<int, pii>	pipii;
const int N = 1010;
int n, m;
int tab[N][N], dis[N][N][4];
map<string, int>mp;
int v[4][2] = {{1, 3}, {0, 2}, {3, 1}, {2, 0}};

int bfs(int i, int j, int k, int l, int dir){
	
	if(tab[i][j] || tab[k][l])
		return -1;
		
	memset(dis, -1, sizeof dis);
	
	queue<pipii>q;
	q.push(make_pair(dir, make_pair(i, j))); 
	dis[i][j][dir] = 0;
	
	while(!q.empty()){
		pipii u = q.front();
		q.pop();
		
		int tx = u.second.first;
		int ty = u.second.second;
				
		for(int i = 1 ; i <= 3 ; i++){
			if(u.first == 0){
				tx = u.second.first - i;	
			}else if(u.first == 1){
				ty = u.second.second + i;
			}else if(u.first == 2){
				tx = u.second.first + i;
			}else{
				ty = u.second.second - i;
			}
			
			if(tx >= 1 && tx < n && ty >= 1 && ty < m){
				if(tab[tx][ty] == 1){
					break;
				}
				if(dis[tx][ty][u.first] == -1){
					dis[tx][ty][u.first] = dis[u.second.first][u.second.second][u.first] + 1;
					
					q.push(make_pair(u.first, make_pair(tx, ty)));
				}
			}
		}
		
		for(int i = 0 ; i < 2 ; i++){
			int ndir = v[u.first][i];
			
			if(dis[u.second.first][u.second.second][ndir] == -1){
				dis[u.second.first][u.second.second][ndir] = dis[u.second.first][u.second.second][u.first] + 1;
				q.push(make_pair(ndir, make_pair(u.second.first, u.second.second)));
			}
		}
	}
	
	int best = dis[k][l][dir];
	
	for(int i = 0 ; i < 4 ; i++){
		best = min(best, dis[k][l][i]);
	}
	
	return best;
}

int main (){
	mp["north"] = 0;
	mp["east"] = 1;
	mp["south"] = 2;
	mp["west"] = 3;
	
	while(cin >> n >> m){
		memset(tab, 0, sizeof tab);
		
		if(n == 0 && m == 0){
			break;
		}
		
		for(int i = 1; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				int x;
				
				cin >> x;
				
				if(x){
					tab[i][j] = 1;
					tab[i - 1][j] = 1;
					tab[i - 1][j - 1] = 1;
					tab[i][j - 1] = 1;
				}
			}
		}
		
		int i, j, l, k;
		string dir;

		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				//cout << tab[i][j] << ' ';
			}
		//	cout << '\n';
		}
		
		cin >> i >> j >> l >> k >> dir;	
		
		cout << bfs(i, j, l, k, mp[dir]) << '\n';
	}
	
	return 0;
}
