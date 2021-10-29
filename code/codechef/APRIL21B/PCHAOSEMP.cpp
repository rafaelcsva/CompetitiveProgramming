#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll inf = ll(1e18) + 64LL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll EPSON = ll(5);

ll get(ll lo, ll hi){
    ll d = ((hi - lo) & 1LL) & (rng() & 1LL);

    return ((hi + lo) >> 1LL) + d; 
}

string getans(ll midx, ll midy, ll posx, ll posy){
    string ans;

    if(posx == midx && posy == midy){
        ans = "O";
    }else{
        if(posx > midx){
            ans.push_back('N');
        }else if(posx < midx){
            ans.push_back('P');
        }else{
            ans.push_back('X');
        }

        if(posy > midy){
            ans.push_back('N');
        }else if(posy < midy){
            ans.push_back('P');
        }else{
            ans.push_back('X');
        }
    }

    return ans;
}

string getans2(ll lox, ll hix, ll loy, ll hiy, ll posx, ll posy){
    if(lox == posx || hix == posx || loy == posy || hiy == posy){
        return "O";
    }

    if(lox <= posx && posx <= hix && loy <= posy && posy <= hiy){
        return "IN";
    }else{
        return "OUT";
    }
}

void next(ll &x, ll &y){
    ll r = rand() % 4LL;

    if(r == 0){
        x++;
    }else if(r == 1LL){
        x--;
    }else if(r == 2LL){
        y++;
    }else{
        y--;
    }
}

int main(){
	cin.tie(NULL);

	int t, q, d;

	cin >> t >> q >> d;
    int mx = 0;

	while(t--){
		bool frag = false;
		ll lox = -inf;
		ll hix = inf;
		ll loy = -inf;
		ll hiy = inf;
        ll sig[2] = {-1, 1};
        ll posx = (rng() % (inf - 63LL)) * sig[rng() % 2];
        ll posy = (rng() % (inf - 63LL)) * sig[rng() % 2];
        int qr = 0;
		
		while((hix - lox) > d + 2 || (hiy - loy) > d + 2){
			ll midx = get(lox, hix);
			ll midy = get(loy, hiy);

			// cout << 1 << " " << midx << " " << midy << endl;

			string ans;
            ans = getans(midx, midy, posx, posy);
            qr++;
            next(posx, posy);

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
            // ans = getans2(lox, hix, loy, hiy, posx, posy);
            // qr++;

            // next(posx, posy);

			// if(ans == "O") continue;
			
            int op = rand() % 2;

            if(op){
			    lox++;
            }else{
                hix--;
            }

			// cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

			ans = getans2(lox, hix, loy, hiy, posx, posy);
            qr++;
            next(posx, posy);

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
				// cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

				ans = getans2(lox, hix, loy, hiy, posx, posy);
                qr++;
                next(posx, posy);
			}

			if(ans == "O") continue;
			
			int op = rand() % 2;

            if(op){
			    loy++;
            }else{
                hiy--;
            }

			// cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;

			ans = getans2(lox, hix, loy, hiy, posx, posy);
            qr++;
            next(posx, posy);

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
			// cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;
			// cin >> ans;
            ans = getans2(lox, hix, loy, hiy, posx, posy);
            qr++;
            next(posx, posy);
			assert(ans != "FAILED");
		}

        mx = max(mx, qr);
	}

    printf("%d\n", mx);

	return 0;
}
