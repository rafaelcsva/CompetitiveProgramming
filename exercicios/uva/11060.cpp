#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
string s[N];
map<string, int>mp;
vector<int>graph[N], ord;
int cor[N];

void dfs(int x){
	cor[x] = 1;
	
	for(int i = 0 ; i < graph[x].size() ; i++){
		int v = graph[x][i];
		
		if(cor[v] == 0){
			dfs(v);
		}
	}
	
	ord.push_back(x);
}

int main (){
	int test = 1;
	
	while(cin >> n){
		
		for(int i = 0 ; i < n ; i++){
			cin >> s[i];
			
			mp[s[i]] = i;
		}
		
		if(test > 1){
			cout << '\n';
		}
		
		int m;
		
		cin >> m;
		
		while(m--){
			string u, v;
			cin >> u >> v;
			
			graph[mp[u]].push_back(mp[v]);
		}
		
		for(int i = 0 ; i < n ; i++){
			if(cor[i] == 0){
				dfs(i);
			}
		}
		
		cout << "Case #" << test++ << ": Dilbert should drink beverages in this order: " ;
		
		for(int i = n - 1 ; i >= 0 ; i--){
			string c = i == 0 ? ".\n" : " ";
			
			cout << s[ord[i]] << c;
		}
		
		ord.clear();
		
		for(int i = 0 ; i < n ; i++){
			graph[i].clear();
			cor[i] = 0;
		}
		
		mp.clear();
		
	}
	
	return 0;
}
