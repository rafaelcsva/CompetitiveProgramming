#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(1e4 + 10);
ll t[N], wx[N], wy[N];

int main(){
	freopen("joy.in", "r", stdin);
	freopen("joy.out", "w", stdout);

	ll sx, sy, fx, fy;

	scanf("%lld %lld %lld %lld", &sx, &sy, &fx, &fy);

	int n;
	ll vmax, k;

	scanf("%d %lld %lld", &n, &k, &vmax);

	t[n] = k;

	for(int i = 0 ; i < n ; i++){
		scanf("%lld %lld %lld", &t[i], &wx[i], &wy[i]);
	}

	ll addx = 0LL;
	ll addy = 0LL;

	for(int i = 0; i < n ; i++){
		addx += wx[i] * (t[i + 1] - t[i]);
		addy += wy[i] * (t[i + 1] - t[i]);
	}

	ll fix = addx + sx;
	ll fiy = addy + sy;

	ll dx = fx - fix;
	ll dy = fy - fiy;

	if(dx * dx + dy * dy <= vmax * vmax * k * k){
		double curx = sx;
		double cury = sy;
		int curi = 0;
		double mx = double(dx) / k;
		double my = double(dy) / k;

		printf("Yes\n");

		for(int i = 1 ; i <= k ; i++){
			curx += mx + wx[curi];
			cury += my + wy[curi];

			while(curi + 1 < n && t[curi + 1] <= i){
				curi++;
			}

			printf("%.7lf %.7lf\n", curx, cury);
		}
	}else{
		printf("No\n");
	}

	return 0;
}