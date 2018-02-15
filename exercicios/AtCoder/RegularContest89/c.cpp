#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;
set<int>pot;

typedef struct{
	int t, x, y;
}Point;

Point points[N];

int main (){
	int tmp = 2;
	int k = 0;
	
	/*while(k < 20){
		pot.insert(tmp);
		tmp = tmp * 2;
		
		k++;
	}*/
	
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d%d", &points[i].t, &points[i].x, &points[i].y);
	}
	
	int time = 0;
	bool ok = true;
	
	for(int i = 0 ; i < n ; i++){
		int dis;
		//cout << time << '\n';
		if(i == 0){
			dis = points[i].t - (points[i].x + points[i].y);
		}else{
			dis = points[i].t - time - (abs(points[i - 1].x - points[i].x) + abs(points[i - 1].y - points[i].y));
		}
		
		if(dis < 0){
			ok = false;
			break;
		}
		
		if(dis % 2 == 0){
		
			time = points[i].t;
			
		}else{
			ok = false;
			break;
		}
	}	
	
	if(ok){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}
