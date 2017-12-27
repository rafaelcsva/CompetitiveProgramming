#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int mark[N][N];

int main (){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			mark[i][j] = 1;
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			for(int y = n ; y > j ; y--){
			//	cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
				if(mark[i][j] > 0 && mark[j][y] > 0){
					int m = min(mark[i][j], mark[j][y]);
					
					mark[i][y] += m;
					mark[i][j] -= m;
					mark[j][y] -= m;
				}
			}
		}
	}

	int ans = 0;

	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			if(mark[i][j] > 0){
				ans += mark[i][j];
			//	cout << mark[i][j] << ' ';
			//	cout << i << ' ' << j << '\n';
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
