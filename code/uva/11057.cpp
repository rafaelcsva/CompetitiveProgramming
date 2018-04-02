#include <bits/stdc++.h>

using namespace std;

set<int>st;

int main (){
	int n, t;
	bool ver = false;
	
	while(cin >> n){
		
		for(int i = 0 ; i < n ; i++){
			int x;
			
			cin >> x;
			
			st.insert(x);
		}
		
		int m;
		
		cin >> m;
		
		int a = 0, b = m;
		for(set<int>::iterator it = st.begin() ; it != st.end() ; it++){
			int comp = m - *it;
			
			if(st.find(comp) != st.end()){
				if(abs(b - a) > abs(*it - comp)){
					a = *it;
					b = comp;
				}
			}
		}
		
		cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
		
		
		st.clear();
	}
	
	return 0;
}
