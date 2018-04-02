#include <bits/stdc++.h>

using namespace std;

int fat(int n){
	if(n <= 2)
		return n;
	
	return 6;
}

const int N = 70;
bool usd[N][N][N];

set<int>points;
set<int>::iterator dart1, dart2, dart3;

void gen(){
	for(int i = 0 ; i <= 20 ; i++){
		points.insert(i);
		points.insert(i * 2);
		points.insert(i * 3);
	} 
	
	points.insert(50);
}

int main (){
	int n;
	
	gen();
	
	while(scanf("%d", &n)){
		if(n <= 0){
			break;
		}
		
		int comb = 0, perm = 0;
		
		for(dart1 = points.begin() ; dart1 != points.end() ; dart1++){
			for(dart2 = points.begin() ; dart2 != points.end() ; dart2++){
				for(dart3 = points.begin() ;dart3 != points.end() ; dart3++){
					int d1 = *dart1, d2 = *dart2, d3 = *dart3;
					
					if(d1 + d2 + d3 == n){
						perm++;
						
						if(d1 <= d2 && d2 <= d3){
							comb++;
						}					
					}
				}
			}
		}
		
		if(comb == 0){
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		}else{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	
	return 0;
}
