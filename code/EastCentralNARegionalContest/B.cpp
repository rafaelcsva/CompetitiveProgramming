#include <bits/stdc++.h>

using namespace std;

const int N = int(2e8 + 10);
const int B = int(1e4 + 10);
bool mark[N];
int a[B];

int main(){
	int a1, m;

	scanf("%d %d", &a1, &m);

	if(a1 == m){
		printf("1\n");
		return 0;
	}
	
	mark[a1] = true;
	a[1] = a1;

	int mex = 1;
	int resp = -1;
	int last = a1;

	for(int i = 2 ; i <= B && (resp == -1) ; i++){
		if(mark[m]){
			resp = i;
			break;
		}

		while(mark[mex]){
			mex++;
		}
		// printf("%d\n", mex);

		a[i] = a[i - 1] + mex;

		if(a[i] <= m){
			mark[a[i]] = true;
		}

		if(a[i] == m){
			// printf("aqui\n");
			resp = i;
			break;
		}

		for(int k = 1 ; k < i ; k++){
			int diff = a[i] - a[k];

			if(diff == m){
				resp = i;
				break;
			}

			if(diff <= m)
				mark[diff] = true;
		}
	}

	assert(resp != -1);

	printf("%d\n", resp);

	return 0;
}