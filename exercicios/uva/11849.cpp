#include <bits/stdc++.h>

using namespace std;

set<int>cd;
set<int>::iterator it;

int main (){
	int n, m;

	while(scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0){
			break;
		}

		for(int i = 0 ; i < n ; i++){
			int c;

			scanf("%d", &c);

			cd.insert(c);
		}

		int qtd = 0;

		for(int i = 0 ; i < m ; i++){
			int c;

			scanf("%d", &c);
	
			it = cd.find(c);
	
			if(it != cd.end()){
				qtd++;
			}
		}

		printf("%d\n", qtd);

		cd.clear();
		
	}

	return 0;
}
