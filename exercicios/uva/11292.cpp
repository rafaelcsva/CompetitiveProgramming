#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;
int head[N], kn[N];

int main (){
	int n, m;
	
	while(scanf("%d%d", &n, &m) && n && m){
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &head[i]);
		}
		
		for(int i = 0 ; i < m ; i++){
			scanf("%d", &kn[i]);
		}	
		
		int i = 0, j = 0;
		
		sort(head, head + n);
		sort(kn, kn + m);
		
		int sum = 0;
		
		while(i < n && j < m){
			if(head[i] <= kn[j]){
				sum += kn[j];
				i++, j++;
			}else{
				while(j < m && kn[j] < head[i]){
					j++;
				}
			}
		}
		
		if(i == n){
			printf("%d\n", sum);
		}else{
			printf("Loowater is doomed!\n");
		}
	}

	return 0;
}
