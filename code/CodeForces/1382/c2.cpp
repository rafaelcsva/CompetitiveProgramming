#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;

	cin >> t;

	while(t--){
		int op = 0;

		int n;

		string a, b;

		cin >> n;

		cin >> a >> b;

		vector< int > oper;

		int i = 0, j = n - 1;
		int len = 0;

		while(i <= j){
			if(op){
				if(a[j] != b[n - len - 1]){
					oper.push_back(1);
					// printf("h\n");
				}

				oper.push_back(n - len);
				j--;
			}else{
				if(a[i] == b[n - len - 1]){
					oper.push_back(1);
				}

				oper.push_back(n - len);
				i++;
			}

			op = !op;
			len++;
		}

		cout << oper.size() ;

		for(int u: oper){
			cout << " " << u;

			// for(int i = 0 ; i < u ; i++){
			// 	a[i] = !(a[i] - '0') + '0';
			// }

			// reverse(a.begin(), a.begin() + u);
		}

		cout << "\n";

		// cout << "r: " << a << " " << b << endl;
		oper.clear();
	}

	return 0;
}