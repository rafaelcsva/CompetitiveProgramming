#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;
int v[N];

int LSOne(int b){
	return b & (-b);
}

class BIT{
	private:
		vector<int>val;

	public:
		BIT(int n){
			val.assign(n + 1, 0);
		}

		void adjust(int k, int v){
			int b = k;
	
			while(b < val.size()){
				val[b] += v;
	
				b = b + LSOne(b);
			}
		}

		int rsq(int b){
			int sum = 0;

			while(b){
				sum += val[b];
				b -= LSOne(b);
			}

			return sum;
		}

		int rsq(int l, int r){
			if(l == 1){
				return rsq(r);		
			}else{
				return rsq(r) - rsq(l - 1);
			}
		}
};

int main (){
	int n, q;

	while(scanf("%d%d", &n, &q) != EOF){
		BIT zero(n), neg(n);

		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &v[i]);
	
			if(v[i] == 0){
				zero.adjust(i, 1);
			}else if(v[i] < 0){
				neg.adjust(i, 1);
			}
		}

		while(q--){
			char op;

			scanf("\n%c", &op);
	
			if(op == 'C'){
				int i, x;
	
				scanf("%d %d", &i, &x);
	
				if(x < 0){
					if(v[i] >= 0){
						neg.adjust(i, 1);

						if(v[i] == 0)
							zero.adjust(i, -1);
					}
					
				}else{
					if(v[i] < 0){
						neg.adjust(i, -1);
					
						if(x == 0){
							zero.adjust(i, 1);
						}	
					}else if(v[i] == 0 && x > 0){
						zero.adjust(i, -1);
					}else if(v[i] > 0 && x == 0){
						zero.adjust(i, 1);
					}
				}
		
				v[i] = x;

			}else{
				int l, r;
	
				scanf("%d%d", &l, &r);

				int a = zero.rsq(l, r), b = neg.rsq(l, r);
				
				if(a){
					printf("0");
				}else{
					if(b % 2 != 0){
						printf("-");
					}else{
						printf("+");
					}
				}
			}
		}
	
		printf("\n");
	}

	return 0;
}
