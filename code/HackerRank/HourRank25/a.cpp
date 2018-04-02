#include <bits/stdc++.h>

using namespace std;

vector<int>numbers;

bool isPossible(){
	int sum = 0;

	for(int i = 0 ;i < numbers.size() ; i++){
		int tmp = numbers[i];
			
		while(tmp){
			sum += tmp % 10;
			tmp = tmp / 10;
		}
	}

	return sum % 3 == 0;
}

int main (){
	int t;

	scanf("%d", &t);

	while(t--){
		int n;
	
		scanf("%d", &n);
	
		int v;

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &v);
	
			numbers.push_back(v);			
		}

		if(isPossible()){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}

		numbers.clear();
	}	

	return 0;
}
