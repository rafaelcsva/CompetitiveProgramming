#include <bits/stdc++.h>

using namespace std;

long double diff = 0.00000009;

bool isEqual(long double a, long double b){
	long double c = fabs(a - b);
	
	return c == 0.000000000;
}

int main (){
	long double a, b, c, inc = 0.05;
	int la, lb, lc;
	
	for(a = inc, la = 0 ; a <= 20.00 ;la++, a += inc){
		for(b = a ; b + a <= 20.00 ;lb++, b += inc){
			for(c = b ; c + a + b <= 20.00 ;lc++, c += inc){
				long double d = (a + b + c) / (a * b * c - 1.00);
			
				if(a == 0.50 && b == 1.00 && c == 2.50){
					printf("founded the value\n");
					return 1;
				}
				
				if(a + b + c + d <= 20.00 && d >= c && isEqual(a + b + c + d, a * b * c * d)){
					printf("%.2Lf %.2Lf %.2Lf %.2Lf\n", a, b, c, d);
				}
			}
		}
	} 

	return 0;
}
