#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

class UnionFind{
	private: int pai[N];

	public: UnionFind(int n){
		for(int i = 1 ; i <= n ; i++){
			pai[i] = i;
		}
	}

	public: int find(int x){
		if(pai[x] == x){
			return x;
		}else{
			return pai[x] = find(pai[x]);
		}
	}

	public: void join(int x, int y){
		int a = find(x);
		int b = find(y);
	
		if(a != b){
			if(a > b){
				pai[a] = b;
			}else{
				pai[b] = a;
			}
		}
	}

};

int main (){
	int t;

	scanf("%d", &t);

	for(int k = 0 ; k < t ; k++){
		int n;

		if(k != 0)
			printf("\n");

		scanf("%d", &n);
	
		UnionFind unioF(n);

		int error = 0, accept = 0;

		while(true){
			char c;

			scanf("%c", &c);

			scanf("%c", &c);

			if(c == '\n'){
				break;
			}
	
			int a, b;

			scanf("%d %d", &a, &b);

			if(c == 'c'){
				unioF.join(a, b);
			}else{
				int x = unioF.find(a);
				int y = unioF.find(b);

				if(x != y){
					error++;
				}else{
					accept++;
				}
			}
		}

		printf("%d,%d\n", accept, error);
	}
	
	return 0;
}
