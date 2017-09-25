#include <bits/stdc++.h>

using namespace std;

int verif[2000];

int main (){
	int n;
	char s[1000];
	int m = 0;

	cin>>n;

	for(int i = 0 ; i < n ; i++)
		cin>>s[i];

	for(int i = 0 ; i < n ; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			int aux = 1;
			
			verif[s[i]] = 1;
			
			for(int j = i+1 ; j < n ; j++){
							
				if(s[j] >= 'a' && s[j] <= 'z'){
					if(!verif[s[j]]){
						aux++;
						verif[s[j]] = 1;
					}
				}else{
					break;
				}
			}

			for(int j = 'a' ; j<='z' ; j++)
				verif[j] = 0;

			m = max(aux, m);
		}
	}

	cout<<m<<'\n';

	return 0;
}