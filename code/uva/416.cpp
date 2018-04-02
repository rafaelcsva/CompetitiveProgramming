#include <bits/stdc++.h>

using namespace std;

const int N = 14;
map<int, string>mp;
string v[N];
set<int>terms[N];
int n;

void gen(){
	mp[0] = "YYYYYYN";
	mp[1] = "NYYNNNN";
	mp[2] = "YYNYYNY";
	mp[3] = "YYYYNNY";
	mp[4] = "NYYNNYY";
	mp[5] = "YNYYNYY";
	mp[6] = "YNYYYYY";
	mp[7] = "YYYNNNN";
	mp[8] = "YYYYYYY";
	mp[9] = "YYYYNYY";
}

bool thereIs(int k, int pos){
	for(int j = k ; j < n ; j++){
		if(v[j][pos] == 'Y'){
			return true;
		}
	}	
	
	return false;
}

bool canInsert(string a, string b, int k){
	for(int i = 0 ; i < a.length() ; i++){
		if(a[i] == 'Y' && b[i] == 'N' || b[i] == 'Y' && a[i] == 'N' && thereIs(k + 1, i)){
			return false;
		}
	}
	
	return true;
}

bool solve(int i, int last){
	if(i == n){
		return true;
	}
	
	if(terms[i].find(last - 1) != terms[i].end()){
		if(solve(i + 1, last - 1)){
		//	cout << last - 1 << ' ';
			return true;
		}
		
		return false;
	}else{
		return false;
	}
}

int main (){
	gen();
	
	ios::sync_with_stdio(false);

	while(cin >> n){
		if(n == 0)
			break;
		
		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
			
			terms[i].clear();
		}

		int last = 10;
		bool ok = false;
		
		for(int i = 0 ; i < n ; i++){
			bool find = false;
			
			for(int j = 9 ; j >= 0 ; j--){
				if(canInsert(v[i], mp[j], i)){
				
					terms[i].insert(j);
				}
			}
		} 
		
		for(int i = 9 ; i >= 0 ; i --){
			if(terms[0].find(i) != terms[0].end()){
				
				ok = ok || solve(1, i);
			}
		}
		
		if(ok){
			cout << "MATCH\n";
		}else{
			cout << "MISMATCH\n";
		}
		
	}
	
	return 0;
}
