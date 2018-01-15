#include <bits/stdc++.h>

using namespace std;

const int N = 1100;
int countChild[N], hasFat[N];
vector<int>tree[N];

int main (){
	int n;

	ios::sync_with_stdio(false);

	cin >> n;	

	for(int i = 2 ; i <= n ; i++){
		int a;

		cin >> a;

		countChild[a]++;

		tree[a].push_back(i);
		hasFat[i] = 1;
	}

	bool ver = true;

	for(int i = 1 ; i <= n ; i++){
		if(countChild[i] > 0 || !hasFat[i]){
			int cnt = 0;

			for(int k = 0 ; k < countChild[i] ; k++){
				if(countChild[tree[i][k]] == 0)
					cnt++;
			}
	
			if(cnt < 3){
				ver = false;
				break;
			}
		}
	}

	if(ver){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}

	return 0;
}
