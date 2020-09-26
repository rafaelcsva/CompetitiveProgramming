#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N];

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int n, m;

		scanf("%d %d", &n, &m);

		set< int > st;

		for(int i = 0 ; i < n ; i++){
			scanf("%d", &a[i]);
			st.insert(a[i]);
		}

		int r = -1;

		for(int i = 0 ; i < m ; i++){
			int xi;

			scanf("%d", &xi);

			if(st.find(xi) != st.end()){
				r = xi;
			}
		}

		if(r != -1){
			printf("YES\n1 %d\n", r);
		}else{
			printf("NO\n");
		}
	}

	return 0;
}