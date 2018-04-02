#include <bits/stdc++.h>

using namespace std;

int A, B, C;

void fill(int v[], int copy[], int n){
	for(int i = 0 ; i < n ; i++){
		copy[i] = v[i];
	}
}

int solve(int copy[]){
	//pegando o mÃ¡ximo de B
	int ansB;
	int tmp = min(copy[0] + copy[1], copy[2]);
	//cout << copy[0] << " " << copy[1] << " tmp\n";
	ansB = tmp * B;
	tmp = 2 * tmp;
	for(int i = 0 ; i < 3; i++){
		int aux = copy[i];
		if(copy[i] > tmp){
			copy[i] -= tmp;
			tmp = 0;
		}else{
			tmp -= copy[i];
			copy[i] = 0;
		}
	
		if(tmp == 0){
			break;
		}
	}			

	ansB += copy[2] * A;

	return ansB;
}

int maxB(int copy[]){
	int ansB = 0;

	if(copy[0] + copy[1] > copy[2]){
				
		if((copy[0] + copy[1] - copy[2]) % 2 != 0){
			if(A + B < C){
				ansB += A + B;
				
			}else{
				ansB += C;
			}
	
			for(int i = 0 ;i < 3 ; i++){
				copy[i]--;
			}
		}
			
		int m = (copy[0] + copy[1] - copy[2]) / 2;

		ansB += m * B;
		//cout << m << '\n';
		//cout << ansB << '\n';
		copy[0] -= m;
		copy[1] -= m;		
	}

	ansB += solve(copy);

	return ansB;
}

int main (){
	int t;

	scanf("%d", &t);

	while(t--){
		int cord[3];
		int copy[3];

		for(int i = 0 ; i < 3 ; i++){
			scanf("%d", &cord[i]);
			copy[i] = cord[i];
		}

		sort(cord, cord + 3);
		sort(copy, copy + 3);

		scanf("%d%d%d", &A, &B, &C);

		//pegando o maximo de A
		int ansA = (cord[0] + cord[1] + cord[2]) * A;

		//pegando o maximo de C
		int ansC = copy[0] * C;
		for(int i = 2 ; i >= 0 ; i--){
			copy[i] -= copy[0];
		}

		ansC += min(copy[1] * B + (copy[2] - copy[1]) * A, (copy[2] + copy[1]) * A);

		/*fill(cord, copy, 3);
		//pegando o maximo de C - 1;
		int ansC1 = (copy[0] - 1) * C;
		for(int i = 2 ; i >= 0 ; i--){
			copy[i] -= copy[0] - 1;
		}
		if(copy[2] != copy[1]){
			ansC1 += min(B * 2 + (copy[1] - 1) * B + (copy[2] - 2) * A, (1 + copy[1] + copy[2]) * A); 
		}else{
			if(cord[0] == copy[1]){
				ansC1 += min(3 * A, B + A);
			}else{
				ansC1 += min(B * 2 + A, A * (1 + copy[1] + copy[2]));
			}
		}*/

		fill(cord, copy, 3);

		int ansB = maxB(copy);

		fill(cord, copy, 3);
		//pegando 1 C e o maximo de B
		int ansCB;
		int tmp = max(1, copy[0] + copy[1] - copy[2]);
		ansCB = C * tmp;
	//	cout << tmp << '\n';
	//	cout << copy[0] << " copy[0]\n";
		for(int i = 0 ; i < 3 ; i++){
			copy[i] -= tmp;
		}
	//	cout << ansCB << " maximo B\n";
		ansCB += maxB(copy);
		//cout << ansC1 << " ansC1\n";
		
		cout << min(ansA, min(ansC, min(ansB, ansCB))) << '\n';
	}

	return 0;
} 
