#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;
int a[N];

int main (){
	int h;
	
	scanf("%d", &h);

	h++;

	for(int i = 0 ; i < h ; i++){
		scanf("%d", &a[i]);
	}

	bool ver = true;

	for(int i = 1 ; i < h ; i++){
		
		if(a[i - 1] > 1 && a[i] > 1){
			ver = false;
			break;
		}
	}

	if(ver){
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	int v = 1;
	printf("0");
	
	for(int i = 1 ; i < h; i++){
		for(int j = 0 ; j < a[i] ; j++){
			printf(" %d", v);
		}
		v += a[i];
	}
	
	printf("\n");
	v = 1;
	printf("0");
	for(int i = 1 ; i < h ; i++){
		if(a[i - 1] > 1 && a[i] > 1){
			printf(" %d", v - 1);
			for(int j = 1 ; j < a[i] ; j++){
				printf(" %d", v);
			}
		}else{
			for(int j = 0; j < a[i] ; j++){
				printf(" %d", v);
			}
		}

		v += a[i];
	}
	printf("\n");

	return 0;
}
