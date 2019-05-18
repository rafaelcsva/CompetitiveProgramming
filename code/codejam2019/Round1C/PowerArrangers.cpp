#include <bits/stdc++.h>

using namespace std;

int ques = 0;
int cnt[30];
string resp = "";
const int N = 1000;
int ask[N];
char answer[N];
const int M = 595;
const int inc = 5;
int f;
bool choosed[30];

void solve(int pos, int sz){
	for(int i = 0 ; i < sz ; i++){
		ques++;
		assert(ques <= f);

		cout << ask[i] + pos << endl;
		char c;

		cin >> c;
		answer[i] = c;
		assert(c != 'N');

		cnt[c - 'A']++;
	}

	int mn_i = -1;

	for(int i = 0 ; i < 5 ; i++){
		if(choosed[i]){
			continue;
		}
		if(mn_i == -1 || cnt[i] < cnt[mn_i]){
			mn_i = i;
		}
	}

	choosed[mn_i] = true;

	resp.push_back(char(mn_i + 'A'));
	memset(cnt, 0, sizeof cnt);

	if(resp.length() == 5){
		return;
	}

	int nw_sz = 0;

	for(int i = 0 ; i < sz ; i++){
		int u = ask[i];

		if(answer[i] == char(mn_i + 'A')){
			ask[nw_sz++] = u;
		}
	}

	solve(pos + 1, nw_sz);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;
	cin >> f;

	for(int ts = 1 ; ts <= t ; ts++){
		ques = 0;

		int sz = 0;
		for(int i = 1 ; i <= M ; i += 5){
			ask[sz++] = i;
		}

		// cout << sz << endl;
		memset(choosed, false, sizeof choosed);
		solve(0, sz);
		cout << resp << endl;
		resp = "";

		char r;

		cin >> r;

		set< char > st;

		if(r == 'N'){
			assert(resp.length() == 5);
			set< char > st;

			for(int i = 0 ; i < resp.length() ; i++){
				st.insert(resp[i]);
			}

			while(st.size() == 5);

			break;
		}

		assert(ques <= 150);
	}

	return 0;
}