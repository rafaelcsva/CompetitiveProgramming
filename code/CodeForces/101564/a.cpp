#include <bits/stdc++.h>

using namespace std;

typedef pair< double, double >	pdd;
const int N = int(1e5 + 10);
pdd segx[N], segy[N];
const double eps = double(1e-13);

bool compar(pdd &a, pdd &b){
	double diff1 = b.first - a.first;
	double diff2 = a.second - b.second;

	if(diff1 > eps){
		return true;
	}else if(diff1 < -eps){
		return false;
	}else{
		return diff2 > eps;
	}
}

int main(){
	int nx, ny;
	double w;

	while(scanf("%d %d %lf", &nx, &ny, &w) != EOF){
		if(nx == 0 && ny == 0) break;

		for(int i = 0 ; i < nx ; i++){
			double xi;

			scanf("%lf", &xi);

			segx[i] = {max(double(0.0), xi - w / 2.0), min(xi + w / 2.0, double(75.0))};
		}

		segx[nx] = {0.0, 0.0};
		segx[nx + 1] = {75.0, 75.0};
		nx += 2;

		sort(segx, segx + nx, compar);

		for(int i = 0 ; i < ny ; i++){
			double xi;

			scanf("%lf", &xi);

			segy[i] = {max(double(0.0), xi - w / 2.0), min(xi + w / 2.0, double(100.0))};
		}

		segy[ny] = {0.0, 0.0};
		segy[ny + 1] = {100.0, 100.0};
		ny += 2;

		sort(segy, segy + ny, compar);

		bool test1 = true, test2 = true;

		int i = 0;

		while(i < nx - 1 && test1){
			test1 = false;
			// printf("%lf, %lf\n", segx[i].first, segx[i].second);
			for(int j = i + 1; j < nx ; j++){
				if(segx[j].second - segx[i].second > -eps){
					if(segx[i].second - segx[j].first > -eps){
						test1 = true;
						i = j;
						break;
					}else{
						// printf("falha na %d\n", i);
						test1 = false;
						break;
					}
				}
			}	

			// printf("%d\n", i);
		}

		i = 0;

		while(i < ny - 1 && test2){
			test2 = false;

			for(int j = i + 1; j < ny ; j++){
				if(segy[j].second - segy[i].second > -eps){
					if(segy[i].second - segy[j].first > -eps){
						test2 = true;
						i = j;
						break;
					}else{
						// printf("falha na %d\n", i);
						test2 = false;
						break;
					}
				}
			}	
		}

		if(test1 && test2){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}