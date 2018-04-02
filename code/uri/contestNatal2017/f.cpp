#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int main (){
	int n;

	cin >> n;

	while(n--){
		char s1[N], s2[N];
		
		scanf("\n%[^\n]s", s1);
		scanf("\n%[^\n]s", s2);

		char nome[2 * N];
		int pos = 0;

		for(int i = 0 ; i < strlen(s1) ; i+=2){
			nome[pos++] = s1[i];
			nome[pos++] = s1[i + 1];
			nome[pos++] = s2[i];
		
			if(i + 1 < strlen(s2))
				nome[pos++] = s2[i + 1];			
		}
		nome[pos] = '\0';

		printf("%s\n", nome);
	}
	
}
