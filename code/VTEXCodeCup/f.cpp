#include <bits/stdc++.h>

using namespace std;

bool compar_less(vector< int > &a, vector< int > &b){
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] < b[i]){
			return true;
		}else if(a[i] > b[i]){
			return false;
		}
	}

	return false;
}

bool put(vector< int > &a, vector< int > &b){
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] >= b[i]){
			return false;
		}
	}

	return true;
}

vector< vector< int > > com;

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		vector< int > tmp;

		for(int j = 0 ; j < 3 ; j++){
			int x;

			scanf("%d", &x);

			tmp.push_back(x);
		}

		sort(tmp.begin(), tmp.end());

		com.push_back(tmp);
	}

	sort(com.begin(), com.end(), compar_less);

	bool ok = true;

	for(int i = 1 ; i < com.size() ; i++){
		if(!put(com[i - 1], com[i])){
			ok = false;
			break;
		}
	}

	if(ok){
		printf("S\n");
	}else{
		printf("N\n");
	}

	return 0;
}