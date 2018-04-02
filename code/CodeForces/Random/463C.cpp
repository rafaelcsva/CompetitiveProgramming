#include <bits/stdc++.h>

#define lli	long long int
using namespace std;

const int N = 2 * (1e3) + 10;
lli tab[N][N];
lli preP[N][N], preS[N][N];

int main (){
	int n;
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> tab[i][j];
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			preP[i][j] = tab[i][j];
			preS[i][j] = tab[i][j];

			if(i > 0 && j > 0){
				preP[i][j] += preP[i - 1][j - 1];
			
			}
			
			if(i > 0 && j < n - 1){
				preS[i][j] += preS[i - 1][j + 1];
			}
			
		}
	}

	int posi1, posj1, posi2, posj2;	
	lli max1 = -1, max2 = -1;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int m = min(n - i, n - j) - 1;
			int k = min(n - i - 1, j);
			lli c = preP[i + m][j + m] + preS[i + k][j - k] - tab[i][j];
		
		//	cout << i << ' ' << j << " mapped to : " << i + k << ' ' << j - k << "\nPval = " << preP[i + m][j + m] << "\nSval = " << preS[i + k][j - k] << '\n';
			if((i + j) % 2 == 0){
				if(c > max1){
					posi1 = i + 1;
					posj1 = j + 1;
	
					max1 = c;
				}	
			}else{
				if(c > max2){
					posi2 = i + 1;
					posj2 = j + 1;
					max2 = c;
				}
			}			
		}
	}

	cout << max1 + max2 << '\n';
	cout << posi1 << ' ' << posj1 << ' ' << posi2 << ' ' << posj2 << '\n';

	return 0;
}
