#include <bits/stdc++.h>

using namespace std;

vector<int>v;

bool CanInsert(int k){
	for(int i = 0 ; i < v.size() ; i++){
		if(v[i] % k == 0 )
			return false;
	}	
	
	return true;
}

int main (){
	int t;
	
	cin >> t;
	
	while(t--){
		int a, b, x;
		
		cin >> a >> b;
		cin >> x;
		
		for(int i = b ; i >= a ; i--){
			if(CanInsert(i)){
				v.push_back(i);
			}
		}
		
		if(v.size() >= x){
			for(int i = 0 ; i < x ; i++){
				cout << v[i];
				
				if(i != v.size()-1){
					cout << " ";
				}
			}
			
			cout << '\n';
		}else{
			cout << "-1\n";
		}
		
		v.clear();
	}
	
	return 0;
}
