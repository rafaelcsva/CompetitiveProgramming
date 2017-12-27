#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
map<char, stack<char> >pilhas;

int main (){
	string s;
	int t = 0;

	while(cin >> s){
		if(s == "end"){
			break;
		}

		t++;	

		for(int i = 0 ; i < s.length() ; i++){
			bool find = false;
			char mark = -1;
		
			for(char k = 'A' ; k <= 'Z' ; k++){
				if(pilhas[k].size() > 0 && s[i] <= pilhas[k].top()){	
					find = true;
					pilhas[k].push(s[i]);
					break;
				}else if(mark == -1 && pilhas[k].size() == 0){
					mark = k;
				}
			}

			if(!find){
			//	cout << i << '\n';
				pilhas[mark].push(s[i]);
			}
		}

		int ans = 0;

		for(char k = 'A' ; k <= 'Z' ; k++){
			if(pilhas[k].size() > 0){
				ans++;
			}
		}
		
		cout << "Case " << t << ": ";
		cout << ans << '\n';

		pilhas.clear();
	}

	return 0;
}
