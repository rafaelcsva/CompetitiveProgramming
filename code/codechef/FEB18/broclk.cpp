#include <bits/stdc++.h>

using namespace std;

typedef long long int	lli;
lli d, i, t;
const lli mod = (lli) 1e9 + 7;	

lli MOD(lli x){
	return (x + mod) % mod;
}

lli mod1(lli a, lli b)
{
    lli r = a % b;

    /* Uma correção é necessária se r e b não forem do mesmo sinal */

    /* se r for negativo e b positivo, precisa corrigir */
    if ((r < 0) && (b > 0))
	return (b + r);

    /* Se r for positivo e b negativo, nova correção */
    if ((r > 0) && (b < 0))
	return (b + r);

    return (r);
}

lli euclides_ext(lli a, lli b, lli c)
{
    lli r;

    r = mod1(b, a);

    if (r == 0) {
		return (mod1((c / a), (b / a)));	// retorna (c/a) % (b/a)
    }

    return ((euclides_ext(r, a, -c) * b + c) / (mod1(a, b)));
}

lli base;

lli fastCos(lli x){
	if(x == 1LL){
		return base;
	}
	
	lli y = fastCos(x / 2LL);
	
	if(x % 2LL){
		y = MOD(y * base) - MOD((1LL - MOD(y * y)) * (1LL - MOD(base * base)));
		y = MOD(y);
	}else{
		y = MOD(y * y);
		y *= 2LL;
		y--;
	}
	
	return MOD(y);
}

int main (){
	int T;
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%lld%lld%lld", &i, &d, &t);
		
		base = MOD(d * (euclides_ext(i, mod, 1)));
		
		cout << MOD(fastCos(t) * i) << '\n';
		
		if(MOD(base * base) == base){
			cout << "YES\n";
		}
	}

	return 0;
}
