#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// Return (X, Y) where Y = lcm(n, m) and X = a mod n and X = b mod m and 0 <= X < Y
// X = -1 if there is not solution
pair<ll, ll> crt(ll a, ll n, ll b, ll m){
	if(a < 0) a += n;
	if(a >= n) a %= n;
	if(b < 0) b += m;
	if(b >= m) b %= m;

	ll x1, x2;
	ll d = gcd(n, m, x1, x2);
	ll lcm = n * m / d;
	if((a - b) % d != 0) 
		return {-1, lcm};

	ll x = (a + (n*x1) * (__int128)((b - a)/d)) % lcm;
	if(x < 0) x += lcm;
	return {x, lcm};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test = 0;

	while(++test){
		ll p, e, i, d;
		cin >> p >> e >> i >> d;

        if(p == -1) break;

		pair<ll, ll> ans = crt(p, 23LL, e, 28LL);
        ans = crt(ans.first, ans.second, i, 33LL);

        cout << "Case " << test << ": the next triple peak occurs in ";
        // ans.first = 19575LL;

        // cout << ans.first % 23LL << " " << ans.first % 28LL << " " << ans.first % 33LL << endl;

        if(ans.first > d){
            cout << ans.first - d;
        }else{
            ll f = (d - ans.first) / ans.second + 1LL;
            ans.first += ans.second * f;
            cout << ans.first - d;
        }

        cout << " days." << endl;
	}

	return 0;
}