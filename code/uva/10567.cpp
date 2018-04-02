#include <bits/stdc++.h>

using namespace std;

const int N = 52, inf = (int) 1e8;
vector<int>ind[N];
vector<int>::iterator it;

int main (){
	string s, tmp;
	
	ios::sync_with_stdio(false);
	
	cin >> s;
	
	for(int i = 0 ; i < s.length() ; i++){
		ind[s[i] - '0'].push_back(i);
	}
	
	int q;
	
	cin >> q;
	
	while(q--){
		cin >> tmp;
		
		int ac = -1;
		int ini = inf;
		
		bool ok = true;
		
		for(int i = 0 ; i < tmp.length(); i++){
			int t = tmp[i] - '0';
			
			it = upper_bound(ind[t].begin(), ind[t].end(), ac);
			
			if(it == ind[t].end()){
				ok = false;
				break;
			}
			
			ac = *it;
			ini = min(ini, ac);
		}
		
		if(ok){
			cout << "Matched " << ini << ' ' << ac << '\n';
		}else{
			cout << "Not matched\n";
		}
	}

	return 0;
}
