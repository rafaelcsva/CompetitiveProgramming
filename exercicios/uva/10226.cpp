#include <bits/stdc++.h>

using namespace std;

typedef long double	lld;
map<string, int>tree;

int main (){
	int t;

	cin >> t;

	for(int i = 1 ; i <= t ; i++){
		char c;

		if(i == 1){
			cin.ignore();
			c = cin.get();
		}else{
			cout << '\n';
		}

		string s;

		int cnt = 0;

		while((c = cin.get()) != '\n' && c != EOF){
			s = c;
			string tmp;

			getline(cin, tmp);

			s = s + tmp;
	
			cnt++;		

			tree[s]++;
		}

		for(map<string, int>::iterator it = tree.begin() ; it != tree.end() ; it++){
			cout << it->first << ' ' << setprecision(4) << fixed << (((lld) it->second) / cnt) * 100 << '\n';
		}

		
		tree.clear();
	}	

	return 0;
}
