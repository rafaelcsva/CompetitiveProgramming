#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int cnt[N];

int main (){
	int r;

	while(cin >> r){
		if(r == -1)
			break;

		cout << "Round " << r << '\n';

		string s;

		cin >> s;

		for(int i = 0 ; i < s.length() ; i++){
			cnt[s[i] - 'a']++;
		}

		string resp;
	
		cin >> resp;

		int corr = 0;
		int error = 0;

		for(int i = 0 ; i < resp.length() && error < 7 && corr < s.length() ; i++){
			if(cnt[resp[i] - 'a'] == -1)
				continue;

			error += !cnt[resp[i] - 'a'];

			corr += cnt[resp[i] - 'a'];
			//cout << s[i] << ' ' << cnt[s[i] - 'a'] << '\n';
			cnt[resp[i] - 'a'] = -1;								
		}

		if(error >= 7){
			cout << "You lose.\n";
		}else if(corr >= s.length()){
			cout << "You win.\n";
		}else{
			cout << "You chickened out.\n";
		}

		for(int i = 0 ; i < 30 ; i++){
			cnt[i] = 0;
		}

	}

	return 0;
}
