#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>	pii;
const int N = 110;
string s[N];
vector<int>graph[N], top;
map<string, int>mp;
priority_queue<int , vector<int>, greater<int>  >pq;
int taked[N], in[N];
int n, m;

void bfs(){
	for(int i = 0 ; i < n ; i++){
		if(in[i] == 0){
			pq.push(i);
		}
	}
	
	while(!pq.empty()){
		int u = pq.top();
		
		pq.pop();
		
		top.push_back(u);
		
		for(int i = 0 ; i < graph[u].size(); i++){
			int v = graph[u][i];
			
			in[v]--;
			
			if(in[v] == 0){
				pq.push(v);
			}
		}
		
	}
}

int main (){
	ios::sync_with_stdio(false);
	
	int test = 1;
	
	while(cin >> n){
		
		for(int i = 0 ; i < n ; i++){
			cin >> s[i];
			
			mp[s[i]] = i;
		}
	
		cin >> m;
		
		while(m--){
			string u, v;
			
			cin >> u >> v;
			
			graph[mp[u]].push_back(mp[v]);
			in[mp[v]]++;
		}
		
		bfs();

		cout << "Case #" << test++ << ": Dilbert should drink beverages in this order: " ;		
		
		for(int i = 0 ; i < n ; i++){
			string c = i == n - 1 ? ".\n\n" : " ";
			
			cout << s[top[i]] << c ;
		}
		
		for(int i = 0 ; i < n ; i++){
			taked[i] = 0;
			in[i] = 0;
			graph[i].clear();
		}
		
		top.clear();
	}

	return 0;
}
