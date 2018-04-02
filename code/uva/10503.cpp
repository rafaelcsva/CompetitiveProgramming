#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

pii lft, rgt;
vector<pii>dominos;

int n, m;

bool backtracking(int put, int mask, int last){
	bool tmp = false;

	if(put == n - 1){
		if(rgt.first == last){
			return true;
		}
	}else{
	
		for(int i = 0 ; i < m ; i++){
			if((mask & (1 << i)) == 0){
				if(dominos[i].first == last){
					tmp = tmp || backtracking(put + 1, mask | (1 << i), dominos[i].second);
				}else if(dominos[i].second == last){
					tmp = tmp || backtracking(put + 1, mask | (1 << i), dominos[i].first);
				}
			}
		}
	}
	
	return tmp;
}

int main (){
	
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			break;
		}
		
		n += 2;
		
		scanf("%d", &m);
		
		cin >> lft.first;
		cin >> lft.second;
		
		cin >> rgt.first;
		cin >> rgt.second;
		
		for(int i = 0 ; i < m ; i++){
			int f, s;
			
			cin >> f >> s;
			
			dominos.push_back(make_pair(f, s));
		}
		
		if(backtracking(1, 0, lft.second)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
		dominos.clear();
	}

	return 0;
}
