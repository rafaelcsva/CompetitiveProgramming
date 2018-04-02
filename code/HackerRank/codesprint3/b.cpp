#include <bits/stdc++.h>

using namespace std;

const int V = 310;
int n;

int vi[V][V];
int graph[V][V];
int maior = 0;

int vx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int vy[8] = {-1, 0, 1, 1, -1, 0, 1, -1};

void bfs(int x, int y, int w, int cnt){
	graph[x][y] = w;
	vi[x][y] = cnt;
	
	queue<pair<int ,pair<int,int>> >q;

	q.push(make_pair(w, make_pair(x, y)));
	
	
	while(!q.empty()){
		pair<int, pair<int,int>>ii = q.front();
		
		q.pop();
		
		int wc = ii.first;
		
		if(wc <= 1)
			continue;
			
		int xu = ii.second.first;
		int yu = ii.second.second;
		
		maior = max(graph[xu][yu] , maior);
		
		for(int i = 0 ; i < 8 ; i++){
			int a = xu+vx[i];
			int b = yu+vy[i];
			
			if(a >= 0 && a < n && b >= 0 && b < n && vi[a][b] != cnt){
				vi[a][b] = cnt;
				
				graph[a][b] += wc-1;
				q.push(make_pair(wc-1, make_pair(a, b)));

			}
		}
	}	
}

int main (){
	char c;
	int m;
	
	cin>>n;
	cin>>m;
	int cnt = 1;
	
	for(int i = 0 ; i < m ; i++){
		int a, b, w;
		
		cin>>a>>b>>w;
	
		bfs(a, b, w, cnt);
		
		cnt++;
	}

	cout<<maior<<'\n';
	
	return 0;
}
