#include <bits/stdc++.h>

using namespace std;

bool isSatisfa(int v[], int i, int j, int k){
	if(v[0] > i || v[1] > j || v[2] > k || v[3] > k)
		return false;

	if(v[0] * 2 < i || v[1] * 2 < j || v[2] * 2 < k || v[3] * 2 < k)
		return false;

	if(i >= k && i <= 2 * k || j >= k && j <= 2 * k)
		return false;

	return true;
}

int main (){
	int v[4];
	
	for(int i = 0 ; i < 4 ; i++){
		cin >> v[i];
	}
	
	for(int i = v[0] ; i <= 2 * v[0] ; i++){
		for(int j = v[1] ; j < i  ; j++){
			for(int k = v[2] ; k < j ; k++){
				if(isSatisfa(v, i, j, k)){
					printf("%d\n%d\n%d\n", i, j, k);
					return 0;
				}
			}
		}
	}

	printf("-1\n");

	return 0;
}
