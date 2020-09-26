#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll mod = 2011;
const ll mod1 = 2e3 + 3;
const int N = mod + 10;

map< vector< int >, double > dp, dp1;

bool ordenado(vector< int > &v){
	for(int i = 1 ; i < v.size() ; i++){
		if(v[i] < v[i - 1]){
			return false;
		}
	}

	return true;
}

double solve(vector< int > v){
	if(ordenado(v)){
		return 0.0;
	}

	if(dp.count(v) != 0){
		return dp[v];
	}

	vector< int > tmp = v;

	int self = 0;
	int cadj = 0;
	double s = 0.0;

	for(int i = 0, j = 1 ; j < v.size() ; i++, j++){
		if(v[i] > v[j]){
			swap(tmp[i], tmp[j]);

			cadj++;

			s += solve(tmp);

			swap(tmp[i], tmp[j]);
		}else{
			self++;
		}
	}

	dp[v] = double(self + cadj + s) / (cadj);

	return dp[v];
}

double solve1(vector< int > v){
	if(ordenado(v)){
		return 0.0;
	}

	if(dp1.count(v) != 0){
		return dp1[v];
	}

	vector< int > tmp = v;
	double s = 0.0;
	int cadj = 0;
	int self = 0;

	for(int i = 0 ; i < v.size() ; i++){
		for(int j = 0 ; j < v.size() ; j++){
			int ii = min(i, j);
			int jj = max(i, j);

			if(v[ii] > v[jj]){
				swap(tmp[ii], tmp[jj]);

				s += solve1(tmp);
				cadj++;

				swap(tmp[ii], tmp[jj]);
			}else{
				self++;
			}
		}
	}

	dp1[v] = double(self + cadj + s) / (cadj);

	return dp1[v];
}

int main(){
	int te;

	scanf("%d", &te);

	while(te--){
		int n;

		scanf("%d", &n);

		vector< int > t, vv;
		
		for(int i = 0 ; i < n ; i++){
			int xi;

			scanf("%d", &xi);

			t.push_back(xi);
		}

		printf("Monty %.6lf Carlos %.6lf\n", solve1(t), solve(t));

		t.clear();
	}

	return 0;
}