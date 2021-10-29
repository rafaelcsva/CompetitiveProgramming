#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const ll inf = ll(1e18) + 64LL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll EPSON = ll(1e15);

ll get(ll lo, ll hi){
	ll add = ((hi - lo) & 1LL) & (rng() & 1LL);
	if(hi - lo > EPSON && rng() % 5 == 0){
		add = 0LL;
        return lo + rng() % (hi - lo);
	}
    // if(add){
    //     cout << "Using rand!\n";
    // }

	return ((hi + lo) >> 1LL) + add;
}

void next(ll &x, ll &y){
    ll d = rng() % 4;

    if(d == 0LL){
        x++;
    }else if(d == 1){
        x--;
    }else if(d == 2){
        y--;
    }else{
        y++;
    }
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

int main(){
	cin.tie(NULL);

	int t, q, d;

	cin >> t >> q >> d;

    int tr = 0;
    ll mr = 0LL;

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
            ll midx = (lox + hix) / 2LL;
            ll midy = (loy + hiy) / 2LL;

            qr++;
			string ans = getans(midx, midy, posx, posy);

			if(ans == "O"){
				frag = true;
				break;
			}

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
            next(posx, posy);

            if(qr >= 61) break;
		}
        // cout << "SAI!\n";

		if(frag) continue;

		string ans = "";

        mr = max(mr, max(hiy - loy,  hiy - loy + hix - lox));
        // cout << "aqui!\n";
        
		while(ans != "O"){
            break;
			// cout << "2 " << lox << " " << loy << " " << hix << " " << hiy << endl;
            // cout << posx << " " << posy << endl;
            if(lox == posx || hix == posx || hiy == posy || loy == posy){
                ans = "O";
            }
            // qr++;
            next(posx, posy);
        	assert(ans != "FAILED");
		}

        tr = max(tr, qr);
    
	}

    cout << tr << " " << mr << endl;

	return 0;
}
