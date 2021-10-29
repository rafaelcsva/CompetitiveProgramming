#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;
const int N = int(5e3 + 1);
ll c[N][N];
const ll inf = ll(1e18);
ll h[N];
vector< ll > dp_before(N), dp_cur(N);

void compute(int l, int r, int optl, int optr, vector< ll > &dp_cur, vector< ll > &dp_before){	
	if(l > r){
		return;
	}

	int mid = (l + r) >> 1;
	pair< ll , int > best = {-inf, -1};

	for(int k = optl ; k <= min(mid, optr) ; k++){
		best = max(best, {dp_before[k] + c[k + 1][mid], k});
	}

	dp_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt, dp_cur, dp_before);
	compute(mid + 1, r, opt, optr, dp_cur, dp_before);
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, k;

        scanf("%d %d", &n, &k);

        for(int i = 0 ; i < n ; i++){
            scanf("%lld", &h[i]);
        }

        for(int i = 0 ; i < n ; i++){
            c[i][i] = h[i];

            for(int j = i - 1 ; j >= 0 ; j--){
                c[j][i] = (c[j + 1][i] | h[j]);

                // printf("%d %d %d\n", j, i, c[j][i]);
            }
        }

        for(int i = 0 ; i < n ; i++){
            dp_cur[i] = c[0][i];
        }

        int tk = k - 1;
        int d = 0;

        while(tk){
            if(d & 1){
                compute(0, n - 1, 0, n - 1, dp_cur, dp_before);
            }else{
                compute(0, n - 1, 0, n - 1, dp_before, dp_cur);
            } 

            tk--;
            d++;
        }

        if((k & 1)){
            printf("%lld\n", dp_cur[n - 1]);
        }else{
            printf("%lld\n", dp_before[n - 1]);
        }
    }

	return 0;
}