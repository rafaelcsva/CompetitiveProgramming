#include <bits/stdc++.h>

#define ll	long long

using namespace std;

const int N = 501000;

ll v[N];
ll pref[N];

int main (){
	int t;

	int n, q;

	ll L, R;

	cin >> n >> q >> L >> R;

	while(q--){
		int op, l, r;

		cin >> op >> l >> r;

		if(op == 1){
			v[l - 1] = r;			
		}else{
			int cnt = 0;
			ll maior;
			int last = l - 1;

			while(!(v[last] >= L && v[last] <= R) && last < r){
				last++;
			}
 
			for(int i = last ; i < r ; i++){

				if(v[i] > v[last]){
					while(!(v[i] >= L && v[i] <= R) && i < r){
						i++;										
						last = i;
					}
				}

				if(i >= r)
					break;

				printf("%d-%d + 1\n", i + 1, last + 1);
				//printf("%d %d\n", i, last);
				cnt += (i - last) + 1;
			}

			cout << cnt << "\n\n";
		}
	}

	return 0;
}
