#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6 + 10);
int a[N];
vector< int > carry;
const int inf = int(1e9);

int main(){
	int t;

	scanf("%d", &t);

	for(int test = 1 ; test <= t ; test++){
		int n;

		scanf("%d", &n);

		n--;

		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &a[i]);
		}

		int f;

		scanf("%d", &f);

		int best = inf;
		int pos = 0;

		for(int j = 0 ; j <= n ; j++){
			if(j & 1){
				carry.push_back(a[j]);
			}

			int mask = carry.size() + n - j;
			// printf("mask %d\n", mask);
			int g = 1;
			int x = -1;
			int current = 0;

			if(j & 1){
				current -= a[j];
			}

			while(mask != 1){
				bool first = false;

				if(mask & 1){
					if(x == -1){
						first = true;
						x = g;
					}else{
						x |= g;
					}
				}

				if(x != -1 && !((mask & 1) && !first)){
					int tmp = x;

					if(carry.size() >= tmp){
						current -= carry[carry.size() - tmp];
					}else{
						tmp -= carry.size();
						current -= a[n - tmp + 1];
					}
				}

				g <<= 1;
				mask >>= 1;
			}

			// printf("x = %d\n", x);
			if(x == -1){
				x = g;
			}else{
				x |= g;
			}

			int tmp = x;
			int last;

			// printf("%d, %d %d\n", j, tmp, g);
			if(carry.size() >= tmp){
				last = carry[carry.size() - tmp];
			}else{
				tmp -= carry.size();
				last = a[n - tmp + 1];
				// printf("aqui!\n");
				assert(n - tmp + 1 >= 1 && n - tmp + 1 <= n);
			}

			// printf("%d\n", last);

			if(last <= f){
				current -= f;			
				// printf("last = %d\n", last);
				// printf("%d %d\n", j, -current);
				if(best > -current){
					best = -current;
					pos = j + 1;
				}
			}
		}

		if(best == inf){
			printf("impossible\n");
		}else{
			// while(best < f);
			assert(pos != n + 1);

			printf("possible\n");
			printf("%d %d\n", pos, best);
		}

		carry.clear();
	}

	return 0;
}
