#include <bits/stdc++.h>

using namespace std;

int main (){
	int n;
	int fences[2010];
	int length[4010];
	
	for(int i = 1 ; i <= 2000; i++){
		fences[i] = 0;
	}
	for(int i = 1; i < 4010 ; i++){
		length[i] = 0;
	}
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		int l;
		
		scanf("%d", &l);
		
		fences[l]++;

	}

	int qtd = 0;
	int max = -1;
	
	for(int i = 1 ; i <= 2000 ; i++){
		for(int j = i ; j <= 2000; j++){
			if(i == j){
				length[i+j] += fences[i]/2;
			}
			else{
				length[i+j] += min(fences[i], fences[j]);
			}
			if(length[i+j] > max)
				max = length[i+j];
		}
	}
	
	for(int i = 1; i < 4010 ; i++){
		if(length[i] == max)
			qtd++;
	}
	
	printf("%d %d\n",max ,qtd);
	
	return 0;
	
}
