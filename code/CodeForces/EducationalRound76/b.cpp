#include <bits/stdc++.h>

using namespace std;

set< unsigned int > st;

int main(){
	int t;

	scanf("%d", &t);

	unsigned int x, y;

	while(t--){
		scanf("%u %u", &x, &y);

		if(x == 1 && y != 1){
			printf("NO\n");
		}else{
			st.insert(x);

			while(x < y){
				if(x & 1){
					x = (x - 1);
				}else{
					x = ((3 * x) / 2);
				}

				if(st.find(x) != st.end()){
					break;
				}

				st.insert(x);
			}

			if(x < y){
				printf("NO\n");
			}else{
				printf("YES\n");
			}

			st.clear();
		}
	}

	return 0;
}