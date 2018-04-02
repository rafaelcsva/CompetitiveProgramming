#include <bits/stdc++.h>

using namespace std;

map<string, string>pai;
map<string, int>peso;

string find(string s1){
	if(pai[s1] == s1){
		return s1;
	}else{
		return pai[s1] = find(pai[s1]);
	}
}

int main (){
	int t;

	cin >> t;
	
	while(t--){
		int n;
	
		cin >> n;

		string s1, s2;

		for(int i = 0 ; i < n ; i++){
			cin >> s1 >> s2;


			if(pai[s1].length() == 0){
				pai[s1] = s1;
				peso[s1] = 1;
			}

			if(pai[s2].length() == 0){
				pai[s2] = s2;
				peso[s2] = 1;
			}
	
			string a = find(s1);
			string b = find(s2);

	
			if(a == b){
				cout << peso[a] << '\n';
				continue;
			}else{
				if(a > b){
					pai[b] = a;
				}else{
					pai[a] = b;
				}

				int aux = peso[a];
				peso[a] += peso[b];
				peso[b] += aux;
			}

			cout << peso[a] << '\n';
		}

		pai.clear();
		peso.clear();
	}

	return 0;
}
