#include <bits/stdc++.h>

using namespace std;

int notas[13];

int main (){
	int n;
	int intervalos[7] = {2,2,1,2,2,2,1};

	string toms[12] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};

	cin>>n;

	for(int i = 0 ; i < n ; i++){
		int nt;

		scanf("%d", &nt);

		notas[(nt-1)%12]++;
	}

	bool verif = false;
	int tom;

	for(int i = 0 ; i < 12 ; i++){
		int aux = i;
		int cnt = 0;
		for(int k = 0 ; k < 7; k++){
			aux = (aux+intervalos[k])%12;
			cnt += notas[aux];
		}

		if(cnt == n){
			verif = true;
			tom = i;
			break;
		}
	}

	if(verif){
		cout<<toms[tom]<<'\n';
	}else{
		cout<<"desafinado\n";
	}

	return 0;
}
