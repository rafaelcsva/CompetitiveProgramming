#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6 + 10);
char s[N], t[N];

int main(){
	scanf("%s", s);
	scanf("\n%s", t);

	int n = strlen(s);
	int m = strlen(t);

	int i = 0, j = 0;

	for(; i < n ; i++){
		if(j >= m){
			break;
		}

		if(s[i] == t[j]){
			j++;
		}
	}

	if(j == m){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
}