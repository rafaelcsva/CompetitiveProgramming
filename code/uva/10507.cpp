#include <bits/stdc++.h>

using namespace std;

const int N = 26;
bool isAwake[N];
int used[N];
vector<int>graph[N];

int main (){
	int n;
	int t = 1;

	ios::sync_with_stdio(false);

	while(cin >> n){
		int m;

		cin >> m;
	
		string s;

		cin >> s;
	
		for(int i = 0 ; i < s.length() ; i++){
			int u = s[i] - 'A';
			//cout << s[i] << '\n';

			isAwake[u] = true;
			used[u] = t;
		}

		for(int i = 0 ; i < m ; i++){
			cin >> s;
	
			int u = s[0] - 'A';
			int v = s[1] - 'A';
			//cout << s[0] << "->" << s[1] << '\n';
	
			used[u] = used[v] = t;
			
			//cout << "here\n";
			graph[u].push_back(v);
			graph[v].push_back(u);			
		}
		bool find = true;
		int year = 0;

		while(find){
			find = false;

			for(int i = 0 ; i < N ; i++){
				if(used[i] == t && !isAwake[i]){
					int cnt = 0;	
			
					for(int k = 0; k < graph[i].size() ; k++){
						if(isAwake[graph[i][k]]){
							cnt++;
						}
					}
	
					if(cnt >= 3){
						char c = i + 'A';
						isAwake[i] = true;
						find = true;
						year++;
					}
				}
			}
		}

		bool ver = true;
		int cnt = 0;

		for(int i = 0 ; i < N ; i++){
			graph[i].clear();

			if(used[i] == t){
				if(!isAwake[i]){
					char c = 'A' + i;
					ver = false;
					break;
				}else{
					cnt++;
				}
			}
		}

		if(!ver || cnt != n){
			cout << "THIS BRAIN NEVER WAKES UP\n";		
		}else{
			cout << "WAKE UP IN, "<< year << ", YEARS\n";
		}

		t++;		
	}

	return 0;
}
