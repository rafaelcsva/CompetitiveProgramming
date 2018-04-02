#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e3 + 10, bg = 1, ed = (int) 1e9;

int c[N];
int n, m;
	
bool isPossible(int sum){
	int ac = 0;
	int container = 0;
	
	for(int i = 0 ; i < n ; i++){
		if(c[i] > sum){
			return false;
		}
		
		if(ac + c[i] > sum){
			container++;
			
			ac = c[i];
		}else{
			ac = ac + c[i];
		}
	}
	
	return ac <= sum && container < m;
}

int main (){
	
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &c[i]);
		}
	
		int ini = bg, fim = ed;
		
		while(ini < fim){
			int mid = (ini + fim) / 2;
			
			if(isPossible(mid)){
				//cout << mid << '\n';
				fim = mid;
			}else{
				ini = mid + 1;
			}
		}
		
		printf("%d\n", (ini + fim) / 2);
	}

	return 0;
}
