#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii > points;

int dist(pii a){
	return abs(a.first) + abs(a.second);
}

bool compar(pii a, pii b){
	return dist(a) <= dist(b);
}

int main (){
	int n;
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		int x, y;

		cin >> x >> y;

		points.push_back(make_pair(x, y));
	}

	sort(points.begin(), points.end(), compar);

	int ans = 0;

	for(int i = 0 ; i < n ; i++){
		int x = points[i].first;
		int y = points[i].second;

		if(x < 0){
			ans += 2;
		}

		if(x > 0){
			ans += 2;
		}

		if(y < 0){
			ans += 2;
		}

		if(y > 0){
			ans += 2;
		}

		ans += 2;
	}

	cout << ans << '\n';

	for(int i = 0 ; i < n ; i++){
		int x = points[i].first;
		int y = points[i].second;
		
		if(x < 0){
			cout << "1 " << abs(x) << " L\n";
		}
		if(x > 0){
			cout << "1 " << x << " R\n";
		}
		if(y < 0){
			cout << "1 " << abs(y) << " D\n";
		}
		if(y > 0){
			cout << "1 " << y << " U\n";
		}

		cout << "2\n";

		if(y < 0){
			cout << "1 " << abs(y) << " U\n";
		}
		if(y > 0){
			cout << "1 " << y << " D\n";
		}
		if(x < 0){
			cout << "1 " << abs(x) << " R\n";
		}
		if(x > 0){
			cout << "1 " << x << " L\n";
		}
		

		cout << "3\n";
	}
			
	return 0;
}
