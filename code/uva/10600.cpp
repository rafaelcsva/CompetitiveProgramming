#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
typedef pair<int, int>	pii;
vector<pair<int, pii> > edges;
vector<int>MST;
int best = 0, secondBest = 0;
int f[N];

int find(int x){
	if(f[x] == x){
		return x;
	}
	
	return f[x] = find(f[x]);
}

int join(int u, int v, int index, int flag = 1){
	int x = find(u), y = find(v);
	
//	cout << x << ' ' << y << '\n';
	
	if(x != y){
		if(flag)
			MST.push_back(index);
		
		if(x > y){
			f[x] = y;
		}else{
			f[y] = x;
		}
		
		return 1;
	}
	
	return 0;
}

int main (){
	int t;
	
	scanf("%d", &t);
	
	while(t--){
		int n, m;
		
		scanf("%d%d", &n, &m);
		
		best = secondBest = 0;
		
		for(int i = 1 ; i <= n ; i++){
			f[i] = i;
		}
		
		while(m--){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);

		//	cout << u << ' ' << v << ' ' << w << '\n';
			edges.push_back(make_pair(w, make_pair(u, v)));
		}
		
		sort(edges.begin(), edges.end());
		m = edges.size();
		
		for(int i = 0 ; i < m ; i++){
			pii ii = edges[i].second;
			
			if(join(ii.first, ii.second, i)){
			//	cout << "here\n";
				best += edges[i].first;
			}
		}	
		
		int comp = n;
		
		secondBest = (int) 1e9;
		
		for(int i = 0 ; i < MST.size() ; i++){
			int comp = n;
			int tmp = 0;
			
			for(int j = 1 ; j <= n ; j++){
				f[j] = j;
			}	
		
			for(int k = 0 ; k < edges.size() ; k++){
				if(k == MST[i]){
					continue;
				}
				
				pii ii = edges[k].second;
				
				if(join(ii.first, ii.second, i, 0)){
					comp--;
					tmp += edges[k].first;
				}
			}	
			
			//cout << comp << '\n';
			
			if(comp == 1){
				secondBest = min(secondBest, tmp);
			}
		}
		
		printf("%d %d\n", best, secondBest);
		
		edges.clear(), MST.clear();
	}

	return 0;
}
