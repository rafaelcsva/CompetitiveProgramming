#include <bits/stdc++.h>

using namespace std;

const int N = 52;
char sit[N][20];
int cnt[N];
const int c = 11;
int prior[N];

int is_free(int l){
	int st = 0;

	for(int i = 0 ; i < c ; i++){
		if(sit[l][i] == '-'){
			st++;
		}
	}

	return st;
}

int main(){
	prior[4] = prior[6] = 10;
	prior[2] = prior[8] = 9;
	prior[0] = prior[10] = 8;
	prior[5] = 7;
	prior[1] = prior[9] = 6;

	int r, n;

	while(scanf("%d %d", &r, &n) != EOF){
		memset(cnt, 0, sizeof cnt);

		for(int i = 0 ; i < r + 3 ; i++){
			scanf("\n%s", sit[i]);
		}

		for(int i = 0 ; i < r + 3 ; i++){
			for(int j = 0 ; j < c ; j++){
				if(sit[i][j] == '#' && j != 5){
					cnt[j > 5]++;
				}
			}
		}

		int f1, f2;
		f1 = f2 = 1;

		// printf("%d %d\n", is_free(1), is_free(r / 2 + 2));

		for(int i = 0 ; i < n ; i++){
			vector< pair< int, int > > v;

			if(f1 != 0){
				f1 = is_free(1);
			}

			if(f2 != 0){
				f2 = is_free(r / 2 + 2);
			}
			int lin = 0;

			if(f1 != 0 || f2 != 0){
				if(f1 >= f2){
					lin = 1;
				}else{
					lin = r / 2 + 2;
				}
			}else{
				pair< int, pair< int, int > > ch = {0, {0, 0}};

				for(int k = 0 ; k < n ; k++){
					int d = is_free(k);

					if(d){
						pair< int, pair< int, int > > tmp = {d, {min({k, abs(r / 2 + 1 - k), r + 2 - k}), k}};

						if(tmp.first == ch.first)
							ch = min(ch, tmp);
						else if(tmp.first > ch.first)
							ch = tmp;
					}
				}

				lin = ch.second.second;
			}

			for(int j = 0 ; j < c ; j++){
				if(sit[lin][j] == '-'){
					v.push_back({prior[j], j});
				}
			}

			int chos = 0;

			if(v.size() == 1){
				sit[lin][v[0].second] = char(i + 'a');
				chos = v[0].second;
			}else{			
				sort(v.begin(), v.end(), greater< pair< int, int > >());

				if(v[0].first == v[1].first){

					if(cnt[1] < cnt[0]){
						sit[lin][v[0].second] = char(i + 'a');
						chos = v[0].second;
					}else{
						sit[lin][v[1].second] = char(i + 'a');
						chos = v[1].second;
					}
				}else{
					sit[lin][v[0].second] = char(i + 'a');
					chos = v[0].second;
				}
			}

			if(chos != 5)
				cnt[chos > 5]++;
		}

		for(int i = 0 ; i < r + 3 ; i++){
			printf("%s\n", sit[i]);
		}
	}

	return 0;
}