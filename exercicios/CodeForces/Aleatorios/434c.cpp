#include <bits/stdc++.h>

using namespace std;

bool isConsonant(char c){
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' ;
}

int main (){
	string s;

	cin>>s;

	int qtd = 0;
	bool d = false;

	for(int i = 0 ; i < s.length()-1; i++){
		if(isConsonant(s[i])){
			qtd++;

			if(isConsonant(s[i+1])){
				if(s[i+1]!=s[i]){
					if(qtd + 1 >= 3){
						cout<<s[i]<<' ';
						qtd = 0;
						d = false;

					}else{
						d = true;

						cout<<s[i];
					}
				}else{
					if(d && qtd+1 >= 3){
						cout<<s[i]<<' ';
						qtd = 0;
						d = false;
					}else{
						cout<<s[i];
					}
				}
			}
			else{
				cout<<s[i];
			}
		}else{
			d = false;
			cout<<s[i];
			qtd = 0;
		}

	//	cout<<qtd<<endl;
	}

	cout<<s[s.length()-1]<<'\n';

	return 0;
}
