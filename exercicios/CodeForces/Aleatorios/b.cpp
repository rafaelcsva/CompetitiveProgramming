#include <bits/stdc++.h>

using namespace std;

int flats[110];

int main (){
	int n, m, i, j;

	scanf("%d%d", &n, &m);

	for(int i = 0; i < m ; i++){
		int f, k;

		scanf("%d%d", &k, &f);

		flats[k] = f;
	}
	
	int q = -1;
	bool verif = true;

	for(i = 1 ; i <= 100 ; i++){
		verif = true;
		for(j = 2*i; j <= 100; j+=i){
			if(flats[j] == flats[j-i]){
				verif = false;
				break;
			}
		} 

		if(verif){
			if(q == -1)
				q = i;
			else{
				verif = false;
				break;
			}
		}
	}

	int r;

	
	if(verif&&q!=-1){

	}
	printf("%d\n", r);
	 
	return 0;
}
