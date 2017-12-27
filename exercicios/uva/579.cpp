#include <bits/stdc++.h>

using namespace std;

int main (){
	int h, m;

	while(scanf("%d:%d", &h, &m) != EOF){
		if(h == 0 && m == 0)
			break;

		double ang1 = 6 * m;
		double ang2 = h * 30 + (m / 2.0);
	
		if(ang1 >= ang2){
			printf("%.3lf\n", min(abs(ang1 - ang2), ang2 + 360 - ang1));
		}else{
			printf("%.3lf\n", min(abs(ang1 - ang2), ang1 + 360 - ang2));
		}
	}

	return 0;
}
