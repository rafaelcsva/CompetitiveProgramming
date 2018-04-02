#include <bits/stdc++.h>

using namespace std;

const int N = 710;
vector<int>A[N];

typedef long long int	lli;

int main (){
	int t;

	scanf("%d",&t);

	while(t--){
		int n;

		scanf("%d", &n);

		for(int i = 0 ; i < n ; i++){
			A[i].clear();

			for(int j = 0 ; j < n ; j++){
				int a;
	
				scanf("%d", &a);
				
				A[i].push_back(a);			
			}
		}

		for(int i = 0 ; i < n ; i++){
			sort(A[i].begin() , A[i].end());
		}

		lli sum = A[n - 1][n - 1];
		lli act = sum;
		bool ver = true;

		for(int i = n - 2 ; i >= 0 ; i--){
			bool find = false;

			for(int j = n - 1 ; j >= 0 ; j--){
				if(A[i][j] < act && (i == 0 || A[i][j] > A[i - 1][0])){
					act = (lli)A[i][j];
					sum += act;
					find = true;
	
					break;
				}
			} 
	
			if(!find){
				ver = false;
	
				break;
			}
		}

		if(!ver){
			printf("-1\n");
		}else{
			printf("%lld\n", sum);
		}		
	}

	return 0;
}
