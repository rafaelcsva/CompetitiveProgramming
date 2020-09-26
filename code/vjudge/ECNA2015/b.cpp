#include <bits/stdc++.h>

using namespace std;

vector< int > cx, cy;
const int N = 110;
pair< int, int > p[N], t[N];
int sum1[N * 2][N * 2], sum2[N * 2][N * 2];

int pref1(int l, int i, int j){
	return sum1[l][j] - sum1[l][i - 1];
}

int pref2(int l, int i, int j){
	return sum2[l][j] - sum2[l][i - 1];
}

int main(){
	int nr, nc, n, m;

	scanf("%d %d %d %d", &nr, &nc, &n, &m);

	for(int i = 0 ; i < n ; i++){
		int r, c;

		scanf("%d %d", &r, &c);

		cx.push_back(c + 9 / 2);
		cy.push_back(r + 15 / 2);
		
		p[i] = {r + 15 / 2, c + 9 / 2};
	}

	for(int i = 0 ; i < m ; i++){
		int r, c;

		scanf("%d %d", &r, &c);

		cx.push_back(c + 9 / 2);
		cy.push_back(r + 15 / 2);

		t[i] = {r + 15 / 2, c + 9 / 2};
	}

	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());

	int add = 0;

	for(int i = 0 ; i < n ; i++){
		// printf("%d, %d\n", p[i].first, p[i].second);

		if(p[i].first >= nr || p[i].second >= nc){
			continue;
		}

		p[i].first = lower_bound(cy.begin(), cy.end(), p[i].first) - cy.begin() + 1;
		p[i].second = lower_bound(cx.begin(), cx.end(), p[i].second) - cx.begin() + 1;

		sum1[p[i].first][p[i].second] = 1;

		// printf("%d, %d\n", p[i].first, p[i].second);
	}

	// printf("------\n");

	for(int i = 0 ; i < m ; i++){
		if(t[i].first >= nr || t[i].second >= nc){
			continue;
		}

		t[i].first = lower_bound(cy.begin(), cy.end(), t[i].first) - cy.begin() + 1;
		t[i].second = lower_bound(cx.begin(), cx.end(), t[i].second) - cx.begin() + 1;

		sum2[t[i].first][t[i].second] = 1;
	}

	for(int i = 1 ; i < 2 * N ; i++){
		for(int j = 1 ; j < 2 * N ; j++){
			sum1[i][j] += sum1[i][j - 1];
			sum2[i][j] += sum2[i][j - 1];
		}
	}

	int ans = int(1e9);

	for(int i = 1 ; i < 2 * N ; i++){
		for(int j = i ; j < 2 * N ; j++){
			int sum = 0;
			int resp = int(1e9);

			for(int k = 1 ; k < 2 * N ; k++){
				sum += pref2(k, i, j) - pref1(k, i, j);
				sum = min(sum, 0);

				ans = min(ans, sum);
			}
		}
	}

	printf("%d\n", ans + n);


	return 0;
}