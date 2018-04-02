#include <bits/stdc++.h>

using namespace std;

const int N = 500;
map<string, int>mp;
bool adj[N][N];
string s[N];

int main (){
	int n;
	int test = 1;
	
	while(cin >> n){
		if(n == 0)
			break;
		
		memset(adj, 0, sizeof adj);
		
		int id = 1;
			
		for(int i = 0 ; i < n ; i++){
			int m;
			
			cin >> m;
			
			int p;
			
			for(int j = 0 ; j < m ; j++){
						
				cin >> s[id];
				
				if(mp[s[id]] == 0){
					mp[s[id]] = id;
				}
				
				if(j){
					//cout << s[p] << ' ' << s[mp[s[id]]] << ' ' << p << ' ' << mp[s[id]] << '\n';
					adj[p][mp[s[id]]] = true;
				}		
				
				p = mp[s[id]];
				id++;
			}
		}

		int k;
		
		cin >> k;
		
		for(int i = 0; i < k ; i++){
			string e1, e2;
			
			cin >> e1;
			
			if(mp[e1] == 0){
				s[id] = e1;
				mp[e1] = id++;
			}
			
			cin >> e2;
			
			if(mp[e2] == 0){
				s[id] = e2;
				mp[e2] = id++;
			}
			
			adj[mp[e1]][mp[e2]] = true;
		}
		
		for(int i = 1 ; i < id ; i++){
			for(int j = 1 ; j < id ; j++){
				for(int k = 1 ; k < id ; k++){
					adj[i][j] |= adj[i][k] & adj[k][j];
				}
			}
		}
		
		int find = 0;
		
		for(int i = 1 ; i < id ; i++){
			for(int j = i + 1 ; j < id ; j++){
				if(!adj[i][j] && !adj[j][i]){
					find++;
				}
			}
		}
		
		if(find){
			cout << "Case " << test++ << ", " << find << " concurrent events:\n";
			int printed = 0;
			
			for(int i = 1 ; i < id ; i++){
				for(int j = i + 1 ; j < id ; j++){
					if(!adj[i][j] && !adj[j][i]){
						printed++;
					
						cout << "(" << s[i] << "," << s[j] << ")";
					
						cout << " ";
						
						if(printed == 2)
							break;
						
					}
				}	
				
				if(printed == 2)
					break;
			}
			
			cout << '\n';
		}else{
			cout << "Case " << test++ << ", no concurrent events.\n";
		}
		
		mp.clear();
	}	

	return 0;
}
