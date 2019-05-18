#include <bits/stdc++.h>

using namespace std;

vector< int > vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;	
	int n;

	cin >> n;
	cin >> s;

	int rounds = n - 11;
	int pround = rounds / 2;
	int sec = pround;
	int take = 0;
	bool can = false;

	for(int i = 0 ; i < s.length() && sec ; i++){
		if(s[i] == '8'){
			vec.push_back(i);
		}
	}

	for(int i = 1 ; (i < vec.size()) && sec ; i++){
		int rest = vec[i] - i;

		if(rest > pround){
			can = true;
			break;
		}

		sec--;
	}
	// cout << sec << " " << can << endl;

	if(sec || can){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}

	return 0;
}