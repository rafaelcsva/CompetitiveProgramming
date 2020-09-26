#include <bits/stdc++.h>

using namespace std;

const int K = 26;

struct Vertex {
	int next[K];
	bool leaf = false;
	int p = -1;
	char pch;
	int link = -1;
	int go[K];
	int gain = 0;

	Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
		fill(begin(next), end(next), -1);
		fill(begin(go), end(go), -1);
	}
};

vector< Vertex > t;
int calc[100 * 100 + 10];
const int inf = 10000000;

void add_string(string const &s, int g){
	int v = 0;

	for(char ch: s){
		int c = ch - 'A';

		if(t[v].next[c] == -1){
			t[v].next[c] = t.size();
			t.emplace_back(v, ch);
		}

		v = t[v].next[c];

		// printf("%d\n", v);

		calc[v] = -1;
	}

	t[v].leaf = true;
	t[v].gain += g;
}

int go(int v, char ch);

int get_link(int v){
	if(t[v].link == -1){
		if(v == 0 || t[v].p == 0){
			t[v].link = 0;
		}else{
			t[v].link = go(get_link(t[v].p), t[v].pch);
		}
	}

	return t[v].link;
}

int go(int v, char ch){
	int c = ch - 'A';

	if(t[v].go[c] == -1){
		if(t[v].next[c] != -1){
			t[v].go[c] = t[v].next[c];
		}else{
			t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
		}
	}

	return t[v].go[c];
}

int cost[30];
int dp[100 * 100 + 10][210];
int used[100 * 100 + 10][210];
int test = 1;

int compute(int st){
	if(calc[st] != -1){
		return calc[st];
	}

	int add = 0;
	int tmp = st;

	while(st != get_link(st)){
		add += t[st].gain;
		st = get_link(st);
	}

	add += t[st].gain;

	// printf("%d ->%d\n", tmp, add);

	return calc[tmp] = add;
}

int solve(int st, int b){
	// cout << "state: " << st << " " << b << endl;

	if(b < 0){
		return -inf;
	}

	if(b == 0){
		return compute(st);
	}

	// cout << "passei" << endl;

	int &ans = dp[st][b];
	int &us = used[st][b];

	if(us == test){
		return ans;
	}

	us = test;
	ans = 0LL;

	for(char c = 'A' ; c <= 'Z' ; c++){
		int g = go(st, c);

		if(g != 0){
			ans = max(ans, solve(g, b - cost[c - 'A']));
		}
	}

	ans += compute(st);

	return ans;
}

int main(){
	int te;

	cin >> te;

	while(te--){
		int n, m, b;

		cin >> n >> m >> b;

		for(int i = 0 ; i < n ; i++){
			char c;
			int ci;

			cin >> c >> ci;

			cost[c - 'A'] = ci;
		}

		t.emplace_back();

		for(int i = 0 ; i < m ; i++){
			string s;
			int ci;

			cin >> s >> ci;

			add_string(s, ci);
		}

		// cout << get_link(3) << " " << t[2].next[0] << " " << get_link(1) << endl;

		cout << "Case #" << test++ << ": " << solve(0, b) << "\n";

		t.clear();
	}

	return 0;
}