#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int v[N];
vector<int>lis;
int L[N];
int n = 0;


int main (){
	while(scanf("%d", &v[n++]) != EOF){
		
	}
	
	n--;
	
	int ans = 0;
	
	for(int i = 0 ; i < n ; i++){
		int k = lis.size();
		int ind = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
		
		if(ind == k){
			lis.push_back(v[i]);
		}else if(lis[ind] > v[i]){
			lis[ind] = v[i];
		}
		
		ans = max(ans, (int)lis.size());
		
		L[i] = ind + 1;
	}
	
	printf("%d\n", ans);
	printf("-\n");
	
	lis.clear();
	
	for(int i = n - 1 ; i >= 0 ; i--){
		if(L[i] == ans){
			lis.push_back(v[i]);
			ans--;
		}
	}
	
	
	for(int i = lis.size() - 1 ; i >= 0 ; i--){
		printf("%d\n", lis[i]);

	}
	
	return 0;
}
