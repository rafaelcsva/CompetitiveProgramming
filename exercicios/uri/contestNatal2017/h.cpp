#include <bits/stdc++.h>

using namespace std;

const int N = 100;

bool isSub(string a, string b, int len){
	for(int i = 0 ; i < len ; i++){
		if(a[i] != b[i])
			return false;
	}
	return true;
}

int main (){
	int n;
	string dang[N];

	cin >> n;

	while(n--){
		int t;
		
		cin >> t;

		for(int i = 0 ; i < t ; i++)
			cin >> dang[i];

		int u;

		cin >> u;

		for(int i = 0 ; i < u ; i++){
			string comp;

			cin >> comp;
			bool ver = false;
			for(int k = 0 ; k < t ; k++){
				
				if(dang[k].length() > comp.length())
					continue;

				for(int x = 0 ; x <= comp.length() - dang[k].length() ; x++){
					if(comp.substr(x, dang[k].length()) == dang[k]){
						int ind = x + dang[k].length();

						if(ind < comp.length()){
							if(!(comp[ind] >= 'A' && comp[ind] <= 'Z'))
								continue;
						}

						ver = true;						
						cout << "Abortar\n";
						break;
					}
				}
				
				if(ver)	
					break;
			}
			if(!ver) cout << "Prossiga\n";
		}

		if(n)
			cout << "\n";	
	}

	return 0;
}
