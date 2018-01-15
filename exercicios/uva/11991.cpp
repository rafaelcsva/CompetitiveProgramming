#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 10;
vector<int>listAdj[N];

int main (){
	ios::sync_with_stdio(false);
	int n, m;

	while(cin >> n >> m){
		int v;

		for(int i = 0 ; i < n ; i++){
			cin >> v;

			listAdj[v].push_back(i + 1);
		}

		int k;

		while(m--){
			cin >> k >> v;
	
			if(k > listAdj[v].size()){
				cout << "0\n";
			}else{
				cout << listAdj[v][k - 1] << '\n';
			}
		}

		for(int i = 0 ; i < N ; i++){
			listAdj[i].clear();
		}	
	}
		
	return 0;
}
