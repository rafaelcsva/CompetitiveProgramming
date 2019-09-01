#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;
const int N = int(3e5 + 100);
int idx[N];
int p[N];
int n;

void my_swap(int i, int j){
	idx[p[i]] = j;
	idx[p[j]] = i;
	swap(p[i], p[j]);
}

vector< pii > operations;

void op1(int i, int j){
	if(1 != j){
		operations.push_back({1, j});
		my_swap(1, j);
	}

	if(1 != i){
		operations.push_back({1, i});
		my_swap(1, i);
	}

	if(1 != j){
		operations.push_back({1, j});
		my_swap(1, j);
	}
}

// void op2(int i, int j){
// 	if(j != n){
// 		operations.push_back({j, n});
// 		my_swap(j, n);
// 	}
// 	if(i != n){
// 		operations.push_back({i, n});
// 		my_swap(i, n);
// 	}
// }

void op(int i, int j){
	if(i != j){
		operations.push_back({i, j});
		my_swap(i, j);
	}
}

int main(){
	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &p[i]);

		idx[p[i]] = i;
	}

	for(int i = 1 ; i <= n ; i++){
		if(i != p[i]){
			// printf("%d eh %d\n", i, p[i]);
			if(i > n / 2){
				int j = idx[i];
				//printf("1: %d, %d\n", i, j);

				op1(i, j);
			}else{
				int j = idx[i];

				if(abs(i - j) < n / 2){
					//printf("%d: \n", i);
					if(n - j < n / 2){
						//printf("i: %d\n", i);
						op(1, j);
						op(1, n);
						op(1, j);
						j = idx[i];

						assert(j == n);
					}else{
						op(j, n);
						j = idx[i];
						assert(j == n);
					}
				}

				op(i, j);
			}
		}
	}

	for(int i = 1 ; i <= n ; i++){
		assert(p[i] == i);
	}

	assert(operations.size() <= n * 5);
	printf("%lu\n", operations.size());

	for(pii u: operations){
		assert(abs(u.second - u.first) >= (n / 2));
		printf("%d %d\n", u.first, u.second);
	}

	return 0;
}