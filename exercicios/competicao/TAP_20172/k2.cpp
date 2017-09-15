#include <bits/stdc++.h>


using namespace std;
#define MAXIMO	1010

typedef struct Gear{
	int x, y, r;
}Gear;

Gear gears[MAXIMO];
int dir[12312];
int n;
	
double dist(int i, int x){
	return (gears[i].x-gears[x].x)*(gears[i].x-gears[x].x)+(gears[i].y-gears[x].y)*(gears[i].y-gears[x].y);
}

bool dfs(int x, int sent){
	dir[x] = sent;

	for(int i = 0 ; i < n ; i++){
		if(i == x)
			continue;

		if(dist(i, x) <= (gears[i].r + gears[x].r)*(gears[i].r + gears[x].r)){//se existir aresta...	
			if(dir[i] == 0){
				if(!dfs(i, -sent)){
					return false;
				}
			}
			else if(dir[x] == dir[i])
					return false;
		}
	}

	return true;
}

int main (){

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++)
		scanf("%d%d%d", &gears[i].x, &gears[i].y, &gears[i].r);
	
	bool v = dfs(0, 1);

	if(!v){
		printf("The input gear cannot move.\n");
	}else if(dir[n-1] == 0){
		printf("The input gear is not connected to the output gear.\n");
	}else{
		int k = __gcd(gears[0].r, gears[n-1].r);

		printf("%d:%d\n", dir[n-1]*gears[0].r/k, gears[n-1].r/k); 
	}

	return 0;
}
