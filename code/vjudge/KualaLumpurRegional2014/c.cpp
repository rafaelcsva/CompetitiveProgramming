#include <bits/stdc++.h>

using namespace std;

int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
set< pair< int, int > > visit, add;
char path[256];
int test = 1;

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int x, y;

		scanf("%d %d", &x, &y);

		scanf("\n%s", path);

		int len = strlen(path);

		visit.insert({x, y});

		int dir = 0;

		int cnt = 0;

		for(int i = 0 ; i < len ; i++){
			char c = path[i];

			if(c == 'F'){
				x += vx[dir];
				y += vy[dir];

				if(visit.find({x, y}) != visit.end()){
					add.insert({x, y});
				}else{
					visit.insert({x, y});
				}
			}else if(c == 'R'){
				dir = (dir + 1) % 4;
			}else{
				dir = (dir - 1 + 4) % 4;
			}
		}

		printf("Case #%d: %d %d %lu\n", test++, x, y, add.size());

		visit.clear();
		add.clear();
	}

	return 0;
}