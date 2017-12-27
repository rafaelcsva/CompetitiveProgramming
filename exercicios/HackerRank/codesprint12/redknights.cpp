#include <bits/stdc++.h>

using namespace std;

const int N = 210;
pair<int, int>path[N][N];
int dis[N][N];
int vx[6] = {-2, -2, 0, 2, 2, 0};
int vy[6] = {-1, 1, 2, 1, -1, -2};
string step[6] = {"LR", "LL", "L", "UL", "UR", "R"};

void bfs(int i_start, int j_start, int i_end, int j_end, int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			dis[i][j] = -1;
		}
	}

	queue<pair<int, int> >q;

	dis[i_start][j_start] = 0;
	q.push(make_pair(i_start, j_start));

	while(!q.empty()){
		pair<int, int> ii = q.front();
		q.pop();

		for(int i = 0 ; i < 6 ; i ++){
			int x = vx[i] + ii.first;
			int y = vy[i] + ii.second;

			if(x >= 0 && x < n && y >= 0 && y < n){
				if(dis[x][y] == -1){
					dis[x][y] = 1 + dis[ii.first][ii.second];
					path[x][y] = make_pair(ii.first, ii.second);
					q.push(make_pair(x, y));
				}
			}
		}
	}
}

vector<string> resp;

void solve(int i, int j, int i_start, int j_start, int n){
	//printf("%d %d\n", i, j);
	if(i == i_start && j == j_start)
		return;

	pair<int, int> ii = path[i][j];
	int f = ii.first, s = ii.second;

	for(int k = 0 ; k < 6; k ++){
		int x = vx[k] + i;
		int y = vy[k] + j;

		if(x >= 0 && x < n && y >= 0 && y < n){
			if(x == f && y == s){
				resp.push_back(step[k]);
				break;
			}
		}
	}

	solve(ii.first, ii.second, i_start, j_start, n);
	
}

int main (){
	int n, i_start, j_start, i_end, j_end;

	cin >> n >> i_start >> j_start >> i_end >> j_end;

	bfs(i_start, j_start, i_end, j_end, n);

	if(dis[i_end][j_end] != -1){
		cout << dis[i_end][j_end] << '\n';

		solve(i_end, j_end, i_start, j_start, n);

		for(int i = resp.size() - 1 ; i >= 0 ; i--){
			cout << resp[i] << ' ';
		}

		cout << '\n';
	}else{
		cout << "Impossible\n";
	}

	return 0;
}
