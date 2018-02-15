#include <bits/stdc++.h>

using namespace std;

const int N = 6, M = 5;
set<string>s1, s2;
string grid1[N], grid2[N];
set<string>::iterator it;

void backtrack(int pos, string pass, int t){
	if(pos == M){
		if(t == 1){
			s1.insert(pass);
		}
		else{
			if(s1.find(pass) != s1.end()){
				s2.insert(pass);
			}
		}
	}else{
		for(int k = 0 ; k < N ; k++){
			char c = t == 1 ? grid1[k][pos] : grid2[k][pos];
			 
			backtrack(pos + 1, pass + c, t);
		}
	}
}

int main (){
	int t;
	
	ios::sync_with_stdio(false);
	
	cin >> t;
		
	while(t--){
		int k;
		
		cin >> k;

		for(int i = 0 ; i < 6 ; i++){
			cin >> grid1[i];
		}
		
		for(int i = 0 ; i < 6 ; i++){
			cin >> grid2[i];
		} 		
		
		backtrack(0 , "", 1);
		backtrack(0,"", 2);
		
		if(s2.size() < k){
			cout << "NO\n";
		}else{
			it = s2.begin();
			
			advance(it, k - 1);
			
			cout << *it << '\n';
		}
		
		s1.clear();
		s2.clear();
	}

	return 0;
}
