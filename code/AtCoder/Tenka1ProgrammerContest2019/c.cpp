#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5);
int pref[N];

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; i++){
		char c;

		scanf("\n%c", &c);

		pref[i] = (c == '#');
		
		pref[i] += pref[i - 1];
	}

	int best = 1e9;

	for(int i = 0 ; i <= n ; i++){
		int twhite = pref[i];
		int tblack = (n - i) - (pref[n] - pref[i]);
		
		best = min(best, twhite + tblack);
	}

	printf("%d\n", best);

	return 0;
}