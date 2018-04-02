#include <bits/stdc++.h>

#define ll	long long
#define mod 1000000009

using namespace std;
const int N = 1010;

ll p[N][N];

ll modular(ll a){
	return (a + mod) % mod;
}

void trianguloPascal(){
	p[0][0] = 1;

	for(int i = 1 ; i < N ; i++){
		p[i][0] = p[i][i] = 1;

		for(int j = 1 ; j < i ; j++){
			p[i][j] = modular((p[i-1][j] + p[i-1][j-1]));
		}
	}
}

ll mod1(ll a, ll b)
{
    ll r = a % b;

    /* Uma correção é necessária se r e b não forem do mesmo sinal */

    /* se r for negativo e b positivo, precisa corrigir */
    if ((r < 0) && (b > 0))
	return (b + r);

    /* Se r for positivo e b negativo, nova correção */
    if ((r > 0) && (b < 0))
	return (b + r);

    return (r);
}

ll euclides_ext(ll a, ll b, ll c)
{
    ll r;

    r = mod1(b, a);

    if (r == 0) {
		return (mod1((c / a), (b / a)));	// retorna (c/a) % (b/a)
    }

    return ((euclides_ext(r, a, -c) * b + c) / (mod1(a, b)));
}

int main (){
	int q;
	ll s[N];

	cin >> q;

	trianguloPascal();

	while(q--){
		ll n, k;
		ll coef;

		cin >> n >> k;

		if(n == 1){
			cout << "0\n";
			continue;
		}
		
		coef = n;
		coef = coef % mod;

		s[0] = n - 1;

		for(int i = 1 ; i <= k ; i++){
			coef = (coef * (n % mod)) % mod;

			ll temp = 0;

			for(int j = 0 ; j < i ; j++){
				temp = (temp + (p[i + 1][j] * s[j]) % mod) % mod;
	//		cout << "s["<<j<<"] = "<<s[j] << endl;
			}
			
			s[i] = modular(modular((coef - 1 - temp)) * euclides_ext(p[i+1][i], mod, 1));
		}

		cout << (s[k] - 1) % mod << '\n';
	}

	return 0;
}
