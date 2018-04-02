#include <bits/stdc++.h>

using namespace std;

const int bits = 1 << 20;
const int maxN = 1000000;
bitset<bits>agenda;
bitset<bits>verl, verr;

int main (){
	int n, m;

	while(cin >> n >> m){
		if(n == 0 && m == 0)
			break;

		bool ok = true;

		for(int i = 0 ; i < n ; i++){
			int l, r;
		
			cin >> l >> r;

			if(!ok)
				continue;
			
			if(r - l == 1){
				if(verl[l] == verr[r] && verr[r] == 1){
					//cout << "here0\n";
					ok = false;
					continue;
				}	
			}

			for(int k = l  ; (k <= r) && ok ; k++){
				
				if(agenda[k] == 1){
					ok = false;				
				}

				if(k != l && k != r)
					agenda[k] = 1;
			}
		
			verr[r] = 1;
			verl[l] = 1;
		}

		for(int i = 0 ; i < m ; i++){
			int l, r, t;

			cin >> l >> r >> t;

			if(!ok)
				continue;

			for(int k = 0 ; k + l < maxN && ok; k += t){
				int p = min(maxN, r + k);

				if(p - l - k == 1){
					if(verr[p] == 1 && verl[l + k] == 1){
						ok = false;
						//cout << "here\n";
						break;
					}
				}

				verr[p] = 1;
				verl[l + k] = 1;

				for(int j = l + k ; j <= p && ok; j++){
					if(agenda[j] == 1){
						ok = false;
					}

					if(j != l + k && j != p)
						agenda[j] = 1;
				}
			}
		}

		agenda.reset();
		verl.reset();
		verr.reset();

		if(!ok){
			cout << "CONFLICT\n";
		}else{
			cout << "NO CONFLICT\n";
		}
	}	

	return 0;
}
