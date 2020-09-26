#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int p[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d", &p[i]);
	}

	sort(p, p + n);

	int add = 0;
	int ac = 0;

	for(int i = 0 ; i < n - 1 ; i++){
		if(ac + p[i] > p[n - 1]){
			break;
		}
		
		ac += p[i];
		add++;
	}

	printf("%d\n", add + 1);

	return 0;
}