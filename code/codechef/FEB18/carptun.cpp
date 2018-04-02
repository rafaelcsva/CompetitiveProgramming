#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
int a[N];
long double EPS = 0.0000000009;

int main (){
	int t, n;
	long double c, d, s;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
		}
		
		scanf("%Lf %Lf %Lf", &c, &d, &s);
		
		long double t1 = 0.0, t2 = 0.0, r = 0.0;
		long double ac = 0.00;
		
		for(int i = 0 ; i < n ; i++){
			if(i > 0){
				t1 += d / s;
				t2 += d / s;
				r += d / s;
			}
			
			t1 += a[i];
			
			if(t1 - t2 >= EPS){
				r = t1 + (c - 1.0) * a[i];
				t2 = t1;
			}else{
				r += a[i];
			}
			
			t2 += a[i];
		}
		
		printf("%.9Lf\n", (r - t1));
	}

	return 0;
}
