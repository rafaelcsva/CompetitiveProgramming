#include <bits/stdc++.h>

using namespace std;

int main (){
	int vet1[3], vet2[3];

	for(int i = 0 ; i < 3 ; i++)
		scanf("%d", &vet1[i]);

	for(int i = 0 ; i < 3 ; i++)
		scanf("%d", &vet2[i]);

	sort(vet1, vet1+3);
	sort(vet2, vet2+3);

	bool verif = true;

	for(int i = 0 ; i < 3 ; i++)
		if(vet1[i] != vet2[i]){
			verif = false;
		}

	if(verif){
		int s = vet1[0]*vet1[0] + vet1[1]*vet1[1];

		if(s != vet1[2]*vet1[2])
			verif = false;
	}

	if(verif)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
