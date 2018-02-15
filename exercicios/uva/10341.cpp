#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
long double p, q, r, s, t, u;
long double ini, fim = 1.00, mid;
#define PI 3.14159265

long double eq(long double mid){
	return 	p * exp(-mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * mid * mid + u;
}

int main (){
	ios::sync_with_stdio(false);
	
	while(cin >> p >> q >> r >> s >> t >> u){
		ini = 0.00;
		fim = 1.00;

		if(eq(1.0) <= 0.00 && eq(0.0) >= 0.0){
			for(int i = 0 ; i < N ; i++){
				mid = (ini + fim) / 2.0;
			
				if(eq(mid) < 0){
					fim = mid;
				}else{
				
					ini = mid;
				}
			}
			
			cout << fixed << setprecision(4) << mid << '\n';
		}else{
			cout << "No solution\n";
		}
		
	}
	
	return 0;	
}
