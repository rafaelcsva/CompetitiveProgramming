#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		int cnt = 0;
		
		for(int j = 0 ; j < 5 ; j++){
			int x;
			
			cin >> x;
			
			cnt += x;
		}
		
		if(cnt == 0){
			cout << "Beginner\n";
		}else if(cnt == 1){
			cout << "Junior Developer\n";
		}else if(cnt == 2){
			cout << "Middle Developer\n";
		}else if(cnt == 3){
			cout << "Senior Developer\n";
		}else if(cnt == 4){
			cout << "Hacker\n";
		}else{
			cout << "Jeff Dean\n";
		}
	}	
	
	return 0;
}
