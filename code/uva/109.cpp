#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >	pii;
vector< vector< pii > > kingdoms;


bool ccw(pii a, pii b, pii c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool cw(pii a, pii b, pii c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

void convex_hull(vector< pii > &a){
	if(a.size() == 1){
		return;
	}

	sort(a.begin(), a.end());

	vector< pii > down, up;

	for(int i = 0 ; i < a.size() ; i++){
		while(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])){
			down.pop_back();
		}

		down.push_back(a[i]);
	}

	for(int i = 0 ; i < a.size() ; i++){
		
	}
}

int main(){
	int n;

	while(true){
		scanf("%d", &n);

		vector< int > kingdom;

		for(int i = 0 ; i < n ; i++){
			int xi, yi;

			scanf("%d %d", &xi, &yi);
			
			kingdom.push_back({xi, yi});
		}

		kingdoms.push_back(kingdom);
	}

	for(int i = 0 ; i < kingdoms.size() ; i++){
		kingdoms[i] = convex_hull(kingdoms[i]);
	}

	int xi, yi;

	while(scanf("%d %d", &xi, &yi) != EOF){
		for(int i = 0 ; i < kingdoms.size() ; i++){
			if(belongs_to(xi, yi, kingdoms[i])){
				destroyed[i] = true;
				break;
			}
		}
	}

	double area = 0.0;

	for(int i = 0 ; i < kingdoms.size() ; i++){
		if(destroyed[i]){
			area += calc(kingdoms[i]);
		}
	}

	printf("%.2lf\n", area);

	return 0;
}