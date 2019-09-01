#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;
typedef pair< int, pii > pipii;
vector< pipii > down, up;

bool compar1(pipii a, pipii b){
	return a.second.first > b.second.first;
}

bool compar2(pipii a, pipii b){
	return a.second.first < b.second.first;
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		int xi, yi;

		scanf("%d %d", &xi, &yi);

		if(xi > yi){
			down.push_back({i + 1, {xi, yi}});
		}else{
			up.push_back({i + 1, {xi, yi}});
		}
	}

	sort(up.begin(), up.end(), compar1);
	sort(down.begin(), down.end(), compar2);

	if(up.size() > down.size()){
		printf("%lu\n", up.size());

		for(int i = 0 ; i < up.size() ; i++){
			printf("%d ", up[i].first);
		}

		printf("\n");
	}else{
		printf("%lu\n", down.size());

		for(int i = 0 ; i < down.size() ; i++){
			printf("%d ", down[i].first);
		}

		printf("\n");
	}

	return 0;
}