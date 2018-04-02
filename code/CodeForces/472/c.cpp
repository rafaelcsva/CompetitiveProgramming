#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 100;
typedef long long	ll;
ll u, n;
ll e[N];

int binary_search(int ini, int fim, ll v){
	int ind = -1;
	
	while(ini <= fim){
		int mid = (ini + fim) / 2;
		
		if(e[mid] == v){
			return ind = mid;
		} 
		
		if(e[mid] > v){
			fim = mid - 1;
		}else{
			ini = mid + 1;
			ind = mid;
		}
	}
	
	return ind;
}

int main (){
	cin >> n >> u;
	
	for(int i = 0 ; i < n ; i++){
		cin >> e[i];
	}

	double resp = 0.00;
	bool find = false;
	
	for(int i = 0 ; i <= n - 3; i++){
		int ind = binary_search(i + 2, n - 1, u + e[i]);
		
		if(ind != -1){
			find = true;
			double coef = double(e[ind] - e[i + 1]) / double(e[ind] - e[i]);
			//cout << i << ' ' << ind << '\n';
			
			if(coef - resp >= 0.0000000001){
				resp = coef;
			}
		}
	}
	
	if(find){
		cout << fixed << setprecision(9) << resp << '\n';
	}else{
		cout << "-1\n";
	}
	
	return 0;
}
