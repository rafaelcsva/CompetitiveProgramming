#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main (){
	int n;
	string r = "-1";
    	ll m = 9999999999;

	cin >> n;

	while(n--){
		string s;
		string num;

		cin >> s;
		cin >> num;

		int l = num.length();

		if(l % 2 == 0){
			int cnt7 = 0, cnt4 = 0;

			for(int i = 0 ; i < l ; i++){
				if(num[i] == '7')
					cnt7++;
				else if(num[i] == '4')
					cnt4++;
			}

			if(cnt7 == l / 2 && cnt4 == l / 2){
				int nume = stoll(num);
				if(nume < m){
					r = s;
					m = nume;
				}
			}
		}
	}

	cout << r << endl;

	return 0;
}
