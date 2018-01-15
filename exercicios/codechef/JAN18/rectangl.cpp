#include <bits/stdc++.h>

using namespace std;

int main (){
	int v[4];
	int t;

	scanf("%d", &t);

	while(t--){
		for(int i = 0; i < 4 ; i++){
			scanf("%d", &v[i]);
		}

		sort(v, v + 4);

		if(v[0] == v[1] && v[2] == v[3]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}
