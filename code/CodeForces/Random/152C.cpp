#include <bits/stdc++.h>

using namespace std;

const int N = 1000, M = 30;
int cnt[N];
bool isCounted[M][N];
long long int ans = 1;
const int mod = (int) 1e9 + 7;

int main (){
	int n, m;

	scanf("%d%d", &n, &m);

	for(int i = 0 ; i < n ; i++){
		
		for(int j = 0 ; j < m ; j++){
			char a;

			scanf("\n%c", &a);

			a -= 'A';

			if(!isCounted[a][j]){
				cnt[j]++;
				isCounted[a][j] = true;
			}
		}
	}

	ans = cnt[0];

	for(int i = 1 ; i < m ; i++){
		ans = (ans * cnt[i]) % mod;		
	}

	printf("%lld\n", ans);
	
	return 0;	
}
