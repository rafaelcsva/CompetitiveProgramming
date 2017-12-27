#include <bits/stdc++.h>

using namespace std;

long double frk(long double r){

	if(fabs(r) < 0.01){
		
		return 0;
	}

	return r;
}

int main (){
	long double r, la, lb;

	while(scanf("%Lf%Lf%Lf", &r, &la, &lb) != EOF){
		long double x, y, z;

		la = ((M_PI) * la) / 180.0;
		lb = ((M_PI) * lb) / 180.0;

		y = sin(la) * r;
		r = cos(la) * r;
		
		x = sin(lb) * r;
		z = -(cos(lb) * r);

		x = frk(x);
		y = frk(y);
		z = frk(z);

		printf("%.2Lf %.2Lf %.2Lf\n", x, y, z);
	}	

	return 0;
}
