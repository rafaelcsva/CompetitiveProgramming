#include <bits/stdc++.h>

using namespace std;

int pont[510];

int main (){
	int j, r;
	
	scanf("%d%d", &j, &r);
	
	for(int i = 0 ; i < r ; i++){
		for(int k = 0 ; k < j ; k++){
			int p;
			
			scanf("%d", &p);
			
			pont[k] += p;
		}
	}
	
	int ind = 0;
	
	for(int i = 0 ; i < j; i++){
		if(pont[ind] <= pont[i]){
			ind = i;
		}
	}
	
	printf("%d\n", ind+1);
}
