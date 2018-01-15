#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;

bool verify(lli n, lli k, lli d){
	int i = 1;
	int tmp = k;

	while(i < d && tmp < n){
		tmp *= k;
	}	

	return tmp >= n;
}

int main (){
	lli n, k, d;

	ios::sync_with_stdio(false);

	cin >> n >> k >> d;

	if(verify(n, k, d)){
		int q = n / k;
		int r = n % k;
		int p = k;
		int bg = k - 1;
	
		for(int i = 0 ; i < d ; i++){
			bool cat = false;

			for(int j = bg, cnt = 0 ; cnt < n ; j = (j + 1) % k, cnt++){
				int tmp = 0;

				while(cnt < n && tmp < q){
					if(j == k && !cat){
						cat = true;
						cout << p + 1 << ' ';
					}else{
						cout << j + 1 << ' ';
					}

					tmp++;
					cnt++;
				}
				cnt--;
			}
		
			cout << '\n';
			p --;
			bg = (bg + 1) % k;
		}

	}else{
		cout << "-1\n";
	}

	return 0;
}
