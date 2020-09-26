#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ifstream fin("alex.in");
	ofstream fout("alex.out");

	double w, h;

	fin >> w >> h;

	if(w < h){
		swap(w, h);
	}

	fout << fixed << setprecision(5) << max({min(w / 2.0, h / 2.0), min(h / 3.0, w), min(w / 3.0, h)}) << endl;

	return 0;
}