#include <bits/stdc++.h>

using namespace std;

#define pb	push_back

typedef vector<pair<int, int> > vi;

const int N = 110;
int a[N];
int mark[N];

int main (){
	int n, m, x, y, j, k;
	vi arr;	
		
	cin >> n >> x;

	for(int i = 0 ; i < n ; i++){
		cin >> j >> k;

		arr.pb(make_pair(j, k));
	}
	bool found = true;

	for(int j = arr[0].first ; j <= arr[0].second ; j++){
		mark[j]++;
	}

	for(int i = 1 ; i < arr.size() ; i++){
		if(mark[arr[i].first] > 0){
			for(int k = arr[i].first ; k <= arr[i].second ; k++)
				mark[k]++;
		}
	}	

	for(int i = 0 ; i <= x ; i++){
		if(mark[i] == 0){
			found = false;
			break;
		}
	}

	if(found){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}

	return 0;
}
