#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll inf = ll(1e18) + 64LL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll EPSON = ll(5);

ll get(ll lo, ll hi){
	ll add = ((hi - lo) & 1LL) & (rng() & 1LL);
	if(hi - lo >= EPSON){
		add = 0LL;
	}

	return ((hi + lo) >> 1LL);
}

int main(){
	cin.tie(NULL);

	int t, q, d;

	cin >> t >> q >> d;

	while(t--){
		bool frag = false;
		ll lox = -inf;
		ll hix = inf;
		ll loy = -inf;
		ll hiy = inf;	
		
		while((hix - lox) > d + 2 || (hiy - loy) > d + 2){
			ll midx = get(lox, hix);
			ll midy = get(loy, hiy);

			cout << 1 << " " << midx << " " << midy << endl;

			string ans;

			cin >> ans;

			if(ans == "O"){
				frag = true;
				break;
			}

			assert(ans != "FAILED");

			if(ans[0] == 'P'){
				lox = max(lox - d, -inf);
				hix = midx;
			}else if(ans[0] == 'N'){
				hix = min(hix + d, inf);
				lox = midx;
			}else if(ans[0] == 'X'){
				lox = midx - d;
				hix = midx + d;
			}

			if(ans[1] == 'P'){
				loy = max(loy - d, -inf);
				hiy = midy;
			}else if(ans[1] == 'N'){
				hiy = min(hiy + d, inf);
				loy = midy;
			}else{
			    loy = midy - d;
			    hiy = midy + d;
			}
		}

		if(frag) continue;

		string ans = "";

		if(hix - lox > d + 1){
			// cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

			// cin >> ans;

			// if(ans == "O") continue;
			
			int op = rand() % 2;

            if(op){
			    lox++;
            }else{
                hix--;
            }

			cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

			cin >> ans;

			if(ans == "O") continue;
			if(ans == "OUT"){
                if(op){
                    hix = lox;
                    lox -= 2;
                }else{
                    lox = hix;
                    hix += 2;
                }
			}
		}

		if(hiy - loy > d + 1){
			if(ans == ""){
				cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

				cin >> ans;
			}

			if(ans == "O") continue;
			
			int op = rand() % 2;

            if(op){
			    loy++;
            }else{
                hiy--;
            }

			cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

			cin >> ans;

			if(ans == "O") continue;
			if(ans == "OUT"){
                if(op){
                    hiy = loy;
                    loy -= 2;
                }else{
                    loy = hiy;
                    hiy += 2;
                }
			}
		}

		while(ans != "O"){
			cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;
			cin >> ans;
			assert(ans != "FAILED");
		}
	}

	return 0;
}
