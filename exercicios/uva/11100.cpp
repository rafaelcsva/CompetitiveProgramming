#include <bits/stdc++.h>

using namespace std;

const int N = 10100, M = (int) 1e6 + 10;
int v[N];
int cnt[M];
vector<int> seq[N];

int main (){
	int n;
	bool ver = false;
	
	while(scanf("%d", &n)){
		if(n == 0){
			break;
		}
	
		if(ver){
			printf("\n");
		}
		
		ver = true;
		
		int cap = 0;
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v[i]);
			
			cnt[v[i]]++;
			
			cap = max(cap, cnt[v[i]]);
		}		
		
		sort(v, v + n);
		
		int k = 0;
		
		for(int i = 0; i < n ;){
			int cur = v[i];
			
			while(v[i] == cur){
				seq[k].push_back(v[i]);
				
				k = (k + 1) % cap;
				i++;
			}
			
		}
		
		printf("%d\n", cap);
		
		for(int i = 0 ; i < cap ; i++){
			for(int j = 0 ; j < seq[i].size() ; j++){
				char c = j == seq[i].size() - 1 ? '\n' : ' ';
				
				printf("%d%c", seq[i][j], c);
			}	
		}
		
		for(int i = 0 ; i < cap ; i++){
			seq[i].clear();
		}
		
		for(int i = 0 ; i < n ; i++){
			cnt[v[i]] = 0;
		}
			
	}

	return 0;
}
