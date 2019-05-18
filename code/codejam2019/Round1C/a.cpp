#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
string s[N];
string resp = "";
char defeat[N];
int tmp[N];

bool solve(int pass, int sz){
	if(sz == 0){
		return true;
	}

	if(pass > 500){
		return false;
	}

	set< char > st;

	for(int i = 0 ; i < sz ; i++){
		int idx = tmp[i];
		int pos = pass % s[idx].length();

		st.insert(s[idx][pos]);
	}

	if(st.size() == 3){
		return false;
	}else{
		if(st.size() == 1){
			char u = *st.begin();

			resp.push_back(defeat[u]);
			return true;
		}else{
			char u = *st.begin();
			char v = *next(st.begin());

			if(defeat[u] == v){
				swap(u, v);
			}

			int nw_sz = 0;

			for(int i = 0 ; i < sz ; i++){
				int idx = tmp[i];
				int pos = pass % s[idx].length();

				if(s[idx][pos] == u){
					tmp[nw_sz++] = idx;
				}
			}

			resp.push_back(u);
			return solve(pass + 1, nw_sz);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	defeat['S'] = 'R';
	defeat['R'] = 'P';
	defeat['P'] = 'S';

	int t;
	int ts = 1;

	cin >> t;

	while(t--){
		int a;

		cin >> a;

		for(int i = 0 ; i < a ; i++){
			cin >> s[i];
			tmp[i] = i;
		}

		resp = "";

		cout << "Case #" << ts++ << ": ";

		if(solve(0, a)){
			cout << resp << endl;
		}else{
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}