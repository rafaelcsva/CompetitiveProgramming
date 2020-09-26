#include <bits/stdc++.h>

using namespace std;

vector< int > oshaaball;
vector< int > ghasbaran;

const int N = 1010;
int hit[N];
const int SD = 32;
int n, k;

int hs(int pos){
	if(pos == oshaaball.size()){
		int cnt = 0;

		for(int i = 1 ; i <= n ; i++){
			if(hit[i]){
				cnt++;
			}
		}

		for(int summon: ghasbaran){
			int kill = 0;
			int save = 0;

			for(int i = summon ; i <= n ; i += summon){
				if(hit[i]){
					kill++;
				}else{
					save++;
				}
			}

			cnt += max(0, save - kill);
		}

		return cnt;
	}

	int ans = hs(pos + 1);

	for(int i = oshaaball[pos] ; i <= n ; i += oshaaball[pos]){
		hit[i] ^= 1;
	}

	ans = max(ans, hs(pos + 1));

	return ans;
}

int main(){
	int hunt = 1;
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &k);
		
		for(int i = 0 ; i < k ; i++){
			int xi;

			scanf("%d", &xi);

			if(xi < SD){
				oshaaball.push_back(xi);
			}else{
				ghasbaran.push_back(xi);
			}
		}

		int r = hs(0);

		assert(r <= n);

		printf("Case #%d: %d\n", hunt++, r);

		memset(hit, 0, sizeof hit);

		oshaaball.clear();
		ghasbaran.clear();
	}	

	return 0;
}