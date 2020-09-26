#include <bits/stdc++.h>

using namespace std;

int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	freopen("alarm.in", "r", stdin);
	freopen("alarm.out", "w", stdout);

	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < 24 ; i++){
		for(int j = 0 ; j < 60 ; j++){
			if(cost[i / 10] + cost[i % 10] + cost[j / 10] + cost[j % 10] == n){
				if(i < 10){
					printf("0");
				}
				printf("%d:", i);

				if(j < 10){
					printf("0");
				}

				printf("%d\n", j);

				return 0;
			}
		}
	}

	printf("Impossible\n");

	return 0;
}