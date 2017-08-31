#include <bits/stdc++.h>

using namespace std;

int main (){
	int t;

	scanf("%d", &t);

	for(int i = 0 ; i < t ; i++){
		int n;

		scanf("%d", &n);

		char stick[210];

		for(int j = 0 ; j < n ; j++){
			scanf("\n%c", &stick[j]);
		}

		int maxL = 0;

		for(int i = 0 ; i < n ; i++){
			int n0 = 0, n1 = 0;

			for(int j = i ; j < n ; j++){
				if(stick[j] == '0')
					n0++;
				else
					n1++;

				if(n0 < n1&&maxL < (j+1)-i)
					maxL = j+1;			
			}
		}
	
		printf("%d\n", maxL);
	}

	return 0;
}
