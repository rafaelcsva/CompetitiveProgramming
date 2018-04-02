#include <bits/stdc++.h>

using namespace std;

const int N = 52;
int adj[N][N];
map<string, int>mp;
const int INF = (int) 1e4;

int main (){
	int n, r;
	int test = 1;
	
	while(cin >> n >> r){
		if(n == 0)
			break;
		
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= n ; j++){
				if(i != j)
					adj[i][j] = INF;
			}
		}	
		
		int id = 1;
		
		for(int i = 0 ; i < r ; i++){
			string s1, s2;
			
			cin >> s1 >> s2;
			
			if(mp[s1] == 0)
				mp[s1] = id++;
			
			if(mp[s2] == 0){
				mp[s2] = id++;
			}
			
			adj[mp[s1]][mp[s2]] = adj[mp[s2]][mp[s1]] = 1;
		}
			
		for(int i = 1 ; i <= n ; i++){
			for(int k = 1 ; k <= n ; k++){
				for(int j = 1 ; j <= n ; j++){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);	
				}
			}
		}
		
		cout << "Network " << test++ << ": ";
		 
		int best = -1;
		
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				best = max(best, adj[i][j]);
			}
		}
		
		if(best >= INF){
			cout << "DISCONNECTED\n\n";
		}else{
			cout << best << "\n\n";
		}
		
		mp.clear();
	}	
	
	return 0;
}
