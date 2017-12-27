#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;

	cin >> n;

	while(n--){
		long long int num;

		cin >> num;

		bitset<64> foo (num);
		
		int ans = 0;

		for(int i = 0 ; i < foo.size() ; i++){
			int tmp = 0;
			
			while(i < foo.size() && foo[i] == 1){
				tmp++;
				i++;
			}		
			ans = max(tmp, ans);	
		}
		//cout << '\n';
		cout << ans;
		cout << '\n';
	}
	
}
