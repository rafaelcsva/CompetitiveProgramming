#include <bits/stdc++.h>

using namespace std;

int pos(char c){
	if(c == 'S')
		return 0;
	return 1;
}

int vet[3];

int main (){
	string s;
	int n;

	cin>>n;
	cin>>s;

	int at = pos(s[0]);

	for(int i = 1 ; i < n ; i++){
		if(pos(s[i]) != at){
			at = pos(s[i]);

			vet[at]++;
		}
	}

	if(vet[1] > vet[0])
		cout<<"YES\n";
	else
		cout<<"NO\n";

	return 0;

}
